#ifndef _GAUSS_FIELDS_
#define _GAUSS_FIELDS_

#if !defined( SIXTRL_NO_SYSTEM_INCLUDES )
    #include <math.h>
#endif

#if !defined( SIXTRL_NO_INCLUDES )
    #include "sixtracklib/common/be_beambeam/constants.h"
    #include "sixtracklib/common/be_beambeam/faddeeva_cern.h"
#endif

#if !defined( REAL_T )
    #define REAL_T SIXTRL_REAL_T
  #define REAL_T_UNDEF
#endif

SIXTRL_FN void get_transv_field_gauss_round(REAL_T sigma, REAL_T Delta_x, REAL_T Delta_y, 
                                  REAL_T x, REAL_T y, SIXTRL_ARGPTR_DEC REAL_T* Ex, SIXTRL_ARGPTR_DEC REAL_T* Ey){    
  REAL_T r2, temp;
  
  r2 = (x-Delta_x)*(x-Delta_x)+(y-Delta_y)*(y-Delta_y);
  if (r2<1e-20) temp = sqrt(r2)/(2.*MYPI*EPSILON_0*sigma); //linearised
  else          temp = (1-exp(-0.5*r2/(sigma*sigma)))/(2.*MYPI*EPSILON_0*r2);
  
  (*Ex) = temp * (x-Delta_x);
  (*Ey) = temp * (y-Delta_y);
}



SIXTRL_FN void get_transv_field_gauss_ellip(REAL_T sigma_x, REAL_T sigma_y, REAL_T Delta_x,  REAL_T Delta_y,
                                  REAL_T x, REAL_T y, SIXTRL_ARGPTR_DEC REAL_T* Ex_out, SIXTRL_ARGPTR_DEC REAL_T* Ey_out){
    
  REAL_T sigmax = sigma_x;
  REAL_T sigmay = sigma_y;
  
  // I always go to the first quadrant and then apply the signs a posteriori
  // numerically more stable (see http://inspirehep.net/record/316705/files/slac-pub-5582.pdf)

  REAL_T abx = fabs(x - Delta_x);
  REAL_T aby = fabs(y - Delta_y);
  
  //printf("x = %.2e y = %.2e abx = %.2e aby = %.2e", xx, yy, abx, aby);
  
  REAL_T S, factBE, Ex, Ey;
  REAL_T etaBE_re, etaBE_im, zetaBE_re, zetaBE_im;
  REAL_T w_etaBE_re, w_etaBE_im, w_zetaBE_re, w_zetaBE_im;
  REAL_T expBE;
  
  if (sigmax>sigmay){
    S = sqrt(2.*(sigmax*sigmax-sigmay*sigmay));
    factBE = 1./(2.*EPSILON_0*SQRT_PI*S);

    etaBE_re = sigmay/sigmax*abx;
    etaBE_im = sigmax/sigmay*aby;

    zetaBE_re = abx;
    zetaBE_im = aby;

    //w_zetaBE_re, w_zetaBE_im = wfun(zetaBE_re/S, zetaBE_im/S)
    cerrf(zetaBE_re/S, zetaBE_im/S , &(w_zetaBE_re), &(w_zetaBE_im));
    //w_etaBE_re, w_etaBE_im = wfun(etaBE_re/S, etaBE_im/S)
    cerrf(etaBE_re/S, etaBE_im/S , &(w_etaBE_re), &(w_etaBE_im));

    expBE = exp(-abx*abx/(2*sigmax*sigmax)-aby*aby/(2*sigmay*sigmay));

    Ex = factBE*(w_zetaBE_im - w_etaBE_im*expBE);
    Ey = factBE*(w_zetaBE_re - w_etaBE_re*expBE);
  }
  else if (sigmax<sigmay){
    S = sqrt(2.*(sigmay*sigmay-sigmax*sigmax));
    factBE = 1./(2.*EPSILON_0*SQRT_PI*S);

    etaBE_re = sigmax/sigmay*aby;
    etaBE_im = sigmay/sigmax*abx;

    zetaBE_re = aby;
    zetaBE_im = abx;

    //w_zetaBE_re, w_zetaBE_im = wfun(zetaBE_re/S, zetaBE_im/S)
    cerrf(zetaBE_re/S, zetaBE_im/S , &(w_zetaBE_re), &(w_zetaBE_im));
    //w_etaBE_re, w_etaBE_im = wfun(etaBE_re/S, etaBE_im/S)
    cerrf(etaBE_re/S, etaBE_im/S , &(w_etaBE_re), &(w_etaBE_im));

    expBE = exp(-aby*aby/(2*sigmay*sigmay)-abx*abx/(2*sigmax*sigmax));

    Ey = factBE*(w_zetaBE_im - w_etaBE_im*expBE);
    Ex = factBE*(w_zetaBE_re - w_etaBE_re*expBE);
  }
  else{
    //printf("Round beam not implemented!\n");
    //exit(1);
    Ex = Ey = 1./0.;
  }

  if((x - Delta_x)<0) Ex=-Ex;
  if((y - Delta_y)<0) Ey=-Ey;
  
  (*Ex_out) = Ex;
  (*Ey_out) = Ey;
}



SIXTRL_FN void get_Ex_Ey_Gx_Gy_gauss(REAL_T x, REAL_T  y, 
    REAL_T sigma_x, REAL_T sigma_y, REAL_T min_sigma_diff,
    SIXTRL_ARGPTR_DEC REAL_T* Ex_ptr, SIXTRL_ARGPTR_DEC REAL_T* Ey_ptr, 
    SIXTRL_ARGPTR_DEC REAL_T* Gx_ptr, SIXTRL_ARGPTR_DEC REAL_T* Gy_ptr){
        
    REAL_T Ex, Ey, Gx, Gy;
    
    if (fabs(sigma_x-sigma_y)< min_sigma_diff){

        REAL_T sigma = 0.5*(sigma_x+sigma_y);
                
        get_transv_field_gauss_round(sigma, 0., 0., x, y, &Ex, &Ey);

        Gx = 1/(2.*(x*x+y*y))*(y*Ey-x*Ex+1./(2*MYPI*EPSILON_0*sigma*sigma)
                            *x*x*exp(-(x*x+y*y)/(2.*sigma*sigma)));
        Gy = 1./(2*(x*x+y*y))*(x*Ex-y*Ey+1./(2*MYPI*EPSILON_0*sigma*sigma)
                            *y*y*exp(-(x*x+y*y)/(2.*sigma*sigma)));
    }
    else{
        
        get_transv_field_gauss_ellip(sigma_x, sigma_y, 0., 0., x, y, &Ex, &Ey);

        REAL_T Sig_11 = sigma_x*sigma_x;
        REAL_T Sig_33 = sigma_y*sigma_y;
        
        Gx =-1./(2*(Sig_11-Sig_33))*(x*Ex+y*Ey+1./(2*MYPI*EPSILON_0)*\
                    (sigma_y/sigma_x*exp(-x*x/(2*Sig_11)-y*y/(2*Sig_33))-1.));
        Gy =1./(2*(Sig_11-Sig_33))*(x*Ex+y*Ey+1./(2*MYPI*EPSILON_0)*\
                    (sigma_x/sigma_y*exp(-x*x/(2*Sig_11)-y*y/(2*Sig_33))-1.));
    }
                    
    *Ex_ptr = Ex;
    *Ey_ptr = Ey;
    *Gx_ptr = Gx;
    *Gy_ptr = Gy;    

}

#if defined(REAL_T_UNDEF)
  #undef REAL_T
  #undef REAL_T_UNDEF
#endif

#endif