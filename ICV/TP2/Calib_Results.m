% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 420.376618170087454 ; 417.040317169641469 ];

%-- Principal point:
cc = [ 309.519760110345203 ; 222.549608431925293 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.115831342254891 ; -0.445977051467357 ; -0.005642713618645 ; -0.005181290112430 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 15.573377273949538 ; 14.407329031299863 ];

%-- Principal point uncertainty:
cc_error = [ 6.621517296023994 ; 11.097866233656987 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.079655716295240 ; 0.630781217413468 ; 0.007103487356825 ; 0.006240998759278 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 5;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 1.86238 ; 2.26178 ; -0.577003 ];
Tc_1  = [ -63.7872 ; -111.947 ; 484.369 ];
omc_error_1 = [ 0.00906684 ; 0.0168744 ; 0.0273048 ];
Tc_error_1  = [ 7.61231 ; 12.4982 ; 17.3819 ];

%-- Image #2:
omc_2 = [ 2.35044 ; 1.78497 ; -0.531675 ];
Tc_2  = [ -185.439 ; -76.3793 ; 838.338 ];
omc_error_2 = [ 0.0136634 ; 0.0170294 ; 0.0295634 ];
Tc_error_2  = [ 13.2145 ; 22.0806 ; 30.2816 ];

%-- Image #3:
omc_3 = [ 1.10176 ; 2.72564 ; -0.196884 ];
Tc_3  = [ 14.8545 ; -140.171 ; 524.219 ];
omc_error_3 = [ 0.00816213 ; 0.017302 ; 0.0263751 ];
Tc_error_3  = [ 8.25607 ; 13.5653 ; 18.8177 ];

%-- Image #4:
omc_4 = [ -1.97998 ; -1.90685 ; 1.14701 ];
Tc_4  = [ -82.6807 ; -149.752 ; 645.57 ];
omc_error_4 = [ 0.01918 ; 0.0143931 ; 0.0350142 ];
Tc_error_4  = [ 10.376 ; 17.039 ; 20.8975 ];

%-- Image #5:
omc_5 = [ 1.95388 ; 2.29728 ; -0.469052 ];
Tc_5  = [ -76.9037 ; -129.147 ; 437.52 ];
omc_error_5 = [ 0.00886808 ; 0.0165905 ; 0.027575 ];
Tc_error_5  = [ 6.92215 ; 11.2642 ; 16.0263 ];

