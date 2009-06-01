/*
 * Copyright (c) 2007, 2009 Joseph Gaeddert
 * Copyright (c) 2007, 2009 Virginia Polytechnic Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// autotest fft data
//

#ifndef __LIQUID_AUTOTEST_FFT_RADIX2_DATA_H__
#define __LIQUID_AUTOTEST_FFT_RADIX2_DATA_H__

#include <complex.h>
#define J _Complex_I

// 4-point fft data
float complex xr2_4[] = {
 -0.313626861162 +   0.851517857896*J,
 -0.498341650639 +  -1.261473861825*J,
 -1.514288543603 +  -0.845144710867*J,
 -1.042389683099 +  -0.071643676792*J
};

float complex testr2_4[] = {
 -3.368646738503 +  -1.326744391588*J,
  0.010831497408 +   1.152614536303*J,
 -0.287184071027 +   1.339490685645*J,
  2.390491867474 +   2.240710601223*J
};

// 8-point fft data
float complex xr2_8[] = {
 -0.800518892910 +  -0.329962805176*J,
 -0.318298065420 +  -0.112601235940*J,
  0.733309570279 +   0.284905318131*J,
  0.869984798980 +   1.740127994239*J,
  2.043127482176 +   0.643925412552*J,
 -0.221831465200 +   0.760970058845*J,
 -1.657937039138 +   1.978844483685*J,
 -0.195716504590 +  -0.036156246030*J
};

float complex testr2_8[] = {
  0.452119884178 +   4.930052980306*J,
 -4.721047901071 +  -5.924218076447*J,
  1.111633132821 +  -0.735389369430*J,
  0.310384041332 +   2.605736778390*J,
  0.183842356636 +   0.225371838077*J,
 -4.354123180209 +  -0.806051577844*J,
  3.222838983428 +  -3.164185019450*J,
 -2.609798460396 +   0.228980004989*J
};

// 16-point fft data
float complex xr2_16[] = {
 -0.823470869600 +  -0.114562369581*J,
 -0.112895184855 +  -0.871101796881*J,
  1.061908932415 +   0.056495515854*J,
 -0.557314563753 +  -0.356293429015*J,
 -1.105107708165 +   2.312606422865*J,
  1.527175497796 +   0.066285403920*J,
  0.248428853066 +  -0.087729393934*J,
 -0.965286019722 +  -0.570164506038*J,
  1.475230119949 +  -0.192634293946*J,
 -0.344098006573 +  -0.389543169430*J,
 -0.915997619710 +  -0.289950907324*J,
  0.107218820688 +   1.534790055843*J,
 -1.944696632347 +  -2.141228554657*J,
 -0.773959409856 +   1.689873759465*J,
 -0.798891239056 +  -0.936097811093*J,
  0.089913663149 +   0.096895719452*J
};

float complex testr2_16[] = {
 -3.831841366572 +  -0.192359354500*J,
  0.024897701509 +  -4.383265247799*J,
  2.370244106165 +  -3.921094201999*J,
 -3.049671891780 +   0.839110805797*J,
 -2.203207660046 +  -0.500227194972*J,
 -2.296135610745 +   2.802006180449*J,
  3.102426809827 +   4.074007560138*J,
-10.679633251840 +   1.436198799211*J,
 -1.773350960319 +  -2.593843429132*J,
  7.291141618866 +  -2.127910192523*J,
  6.613626702670 +   1.571197741139*J,
-10.081724683332 +  -2.572280767109*J,
 -1.783780373710 +   2.743154797329*J,
  3.600632242267 +   0.663101260605*J,
  2.719956744782 +  -3.638409226219*J,
 -3.199114041335 +   3.967614556287*J
};

// 32-point fft data
float complex xr2_32[] = {
  0.961067864909 +   0.286335976496*J,
  0.286620373507 +  -1.102677365222*J,
  2.325318943438 +   1.027915910835*J,
 -1.315325966542 +   0.848609514062*J,
 -0.237551072471 +  -0.495697802556*J,
 -1.641791207710 +   0.353159752894*J,
 -0.157082118405 +  -1.650538558328*J,
  0.753530187921 +   0.177783281419*J,
 -1.220432057527 +   0.668419091887*J,
  0.149532110219 +  -0.147897988156*J,
  1.689623713783 +   0.680482332029*J,
  1.012148016504 +  -2.125406594771*J,
 -0.269259848704 +   0.747010004865*J,
  1.125730017419 +   0.268147563672*J,
 -1.571735839429 +  -0.408160795892*J,
  0.640934293631 +   0.567325657726*J,
 -0.160379407251 +  -1.275369007587*J,
  0.634406478832 +   0.854559707293*J,
  1.381740692078 +  -0.631444125756*J,
  0.476916028207 +   0.040060743280*J,
  0.361888381963 +  -0.243726531633*J,
  0.549327875093 +   0.740571341856*J,
 -1.801192169035 +  -2.490384124468*J,
  0.016540491640 +  -0.126387636035*J,
  0.344208443719 +  -0.298722560031*J,
  0.599658245602 +   1.408534651569*J,
  0.697314642427 +  -0.264810930006*J,
  2.201161771758 +   0.905756543393*J,
 -0.304406393087 +  -0.135493365162*J,
 -0.121110444045 +   1.664763081568*J,
  1.579435504748 +   0.808381920570*J,
  0.854073659033 +  -0.452695831243*J
};

float complex testr2_32[] = {
  9.840911212224 +   0.198403858569*J,
  0.372618970380 +   7.435693662330*J,
  0.076404578009 +   7.282339389029*J,
  1.820748529445 +   0.656869874296*J,
  4.316484387888 + -10.929557628048*J,
  6.313222356978 +   0.724181949523*J,
 -2.309394664801 +  -8.519894418185*J,
 -5.374616889095 +  -4.813787879368*J,
 -0.464172390412 +   5.238919210533*J,
 -5.515309916239 +   5.160595487673*J,
 -2.860035925225 +  -4.276652329194*J,
 -1.576150125343 +  -4.195869855930*J,
 -7.120168110622 +   7.305115699457*J,
  1.802861502166 +   9.955901782278*J,
  9.066578438666 +   8.180027098275*J,
 -0.122576870238 +   5.199728432163*J,
 -2.603792649909 +  -7.550008988042*J,
 15.501227509948 +   0.062059053352*J,
 -1.226521458316 +  -4.087437204857*J,
  1.658557984261 +  10.232569797312*J,
  5.536792654850 +  -6.142445209145*J,
 -4.607992311225 +  10.035833135288*J,
 -2.731439208807 +   1.716821202405*J,
 -0.533472442550 +  -6.009621202383*J,
 -8.872402525697 +  -0.876290855939*J,
 -2.015647027690 +  -1.765683735748*J,
  5.314037195827 +  -7.145182311903*J,
  2.292360436768 +  -1.900471664442*J,
 -1.237933827518 +   7.801171918736*J,
  4.857730308302 +  -6.597817452060*J,
  8.085667616379 +  -4.019857929150*J,
  3.069594338684 +   0.807098361039*J
};

float complex xr2_64[] = {
  0.018433802161 +   1.312209206080*J,
  2.158993707240 +  -1.426595952083*J,
 -1.058246453930 +  -0.083532510021*J,
  0.284642267824 +  -0.353585231353*J,
  1.024288545329 +   0.670848790173*J,
  1.099747635395 +   0.408924622105*J,
 -0.813701638498 +  -0.333269715021*J,
 -0.623017439662 +   1.323390342880*J,
 -0.338351606501 +  -1.134432243276*J,
  1.080139708673 +   0.794506792049*J,
  0.465380255690 +   0.667525184347*J,
  0.299331623102 +  -0.957608688378*J,
 -0.694955933076 +  -0.208720098199*J,
  0.370691404618 +   0.833424242145*J,
 -0.159596162745 +  -1.117277876037*J,
 -0.354344124916 +  -0.579183100042*J,
  0.479588760178 +  -0.674895239604*J,
  0.865492259190 +   1.665726619624*J,
 -1.288035328585 +  -0.392681907390*J,
  0.038451073083 +  -1.613792877580*J,
  2.257998205535 +  -0.279479408966*J,
  1.048656703977 +   0.701593281206*J,
  0.493487990178 +  -1.040176731610*J,
 -2.171150746859 +   2.092795197571*J,
  0.268582995273 +  -1.212979630073*J,
 -0.225057526413 +   0.145851026202*J,
  0.476715762402 +   0.468876974239*J,
 -1.067369855919 +  -2.158750381452*J,
 -0.591970305742 +   0.230725856824*J,
  1.133754113738 +   0.571421937539*J,
  0.476292162630 +   0.088594763290*J,
 -0.510461712166 +   0.486897877290*J,
 -0.069410497872 +   0.087237763221*J,
 -0.816043734211 +  -0.942055624944*J,
  1.488697871336 +  -0.680147165475*J,
  0.319109239734 +   1.415714154272*J,
  0.027243479106 +   2.144527588870*J,
 -1.217757631026 +  -0.884074754702*J,
  0.543931309899 +   0.690259574502*J,
  0.083826747171 +   0.688592522379*J,
  0.624811653986 +  -0.507151646195*J,
  0.697612396827 +  -1.190289368728*J,
  0.198205593558 +   0.401473821155*J,
  0.542762562817 +  -0.014683757285*J,
  3.960384191601 +   1.229211978532*J,
  0.161268675259 +   1.772438208096*J,
  2.214322448540 +   0.769350666829*J,
 -1.974419571901 +   1.041367239853*J,
  0.995082900655 +  -0.669239939997*J,
  0.552406517899 +   0.508260831526*J,
 -0.456658258747 +  -2.287526572942*J,
  1.050958221560 +  -0.387708314673*J,
 -1.433201704907 +   0.178309571342*J,
 -1.264609001540 +  -1.675585525157*J,
  1.700631442997 +   0.906348048279*J,
  0.688230071270 +  -1.488458205243*J,
  1.944176953078 +  -1.646485784054*J,
 -0.085953383725 +  -0.466975671912*J,
 -1.596742557356 +  -0.689411588310*J,
  0.204330017630 +  -0.006911022228*J,
 -0.064305007301 +  -0.442729791071*J,
  0.258356597916 +   1.165180662325*J,
  1.059111991139 +   0.345921860019*J,
 -0.162312968292 +   1.589918282697*J
};

float complex testr2_64[] = {
 14.618456708303 +  -0.148970836538*J,
  0.173743766245 +   3.116445605276*J,
  6.440387759045 +   0.180616164784*J,
 10.008422766207 +   8.701763871919*J,
 -2.816340431319 +   7.043152817271*J,
-16.536149412403 +  -7.339456661390*J,
 10.839608299671 +  -2.839557585815*J,
  0.174942261417 +   5.049926468150*J,
-15.556384475630 +  -3.444941405882*J,
  9.431648943102 +   2.532813321428*J,
-10.846203725568 +   0.995525347083*J,
-13.446031379727 +  14.244736202656*J,
 -8.111592876806 +  -0.780629551228*J,
 15.598080928809 +  -7.531970782855*J,
-14.857449430787 +  -1.302127572458*J,
 12.522236701487 +   5.975833542693*J,
  5.568357289580 +  -7.806502891586*J,
 -3.924945245609 +  -9.605778506919*J,
-10.485885842253 +   5.132265750335*J,
  0.348109092406 +  -4.703648753883*J,
  8.675716641276 +  11.539549043034*J,
-14.078544405908 +  -6.889406076012*J,
 -6.638176673281 +   2.139383332381*J,
 -3.007119092566 + -11.476081114143*J,
 -4.006614852801 + -25.691267576574*J,
  5.264305961985 +   7.877965529477*J,
 -0.233119828709 +  18.389191519322*J,
-20.452542658687 +   0.164273418043*J,
 -4.372213889400 +  -4.928918115119*J,
  7.159608279657 +  -0.443728982721*J,
 -7.512154999583 +   5.287801441592*J,
 -5.923851714245 + -10.902498040717*J,
  9.685929011718 +  -6.268461564542*J,
-17.980492003469 +   6.606944935186*J,
 -2.447446806748 +   9.244449470687*J,
  2.325181031944 +  -4.245371626971*J,
 -0.257777557356 +   0.840658066218*J,
  5.830279872010 +  13.262464329851*J,
  4.615003645501 +  -5.732114060914*J,
  7.843750973451 +  18.254814333292*J,
  8.620902747157 +   2.078402722617*J,
-10.800186671850 +  -0.256073316712*J,
  1.205732676510 +   2.788485774582*J,
 -2.845912797193 +   0.683104456189*J,
 -4.870712354761 +  18.260032402943*J,
  3.527319462534 +   5.531290471011*J,
  2.626273014115 +   6.004069061572*J,
 -4.483365988782 +  -6.682177754091*J,
  3.760842716415 +  10.531763187093*J,
  8.155095238193 +   4.716814598080*J,
  6.546192733933 +  -2.848147012748*J,
 18.252470915818 +  10.674058306788*J,
 -2.280824394118 +   1.733382128356*J,
 -9.587922073841 +  -0.080802582028*J,
  2.395656077558 +  -6.795354192934*J,
 -3.163305087462 +  -7.175026418322*J,
  8.691830542923 +  -4.815921745777*J,
 13.272304850513 +   7.860941443988*J,
  7.358208378680 +   3.476669384107*J,
  1.432029426855 +   1.084683568545*J,
  5.429544616774 +   2.743661954926*J,
  5.810876516849 +   8.488986007710*J,
-13.416998982797 +   9.776157560858*J,
  1.910979143300 +  -8.296753622023*J
};

#endif // __LIQUID_AUTOTEST_FFT_RADIX2_DATA_H__
