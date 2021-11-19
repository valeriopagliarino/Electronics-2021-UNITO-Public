// Mainframe macro generated from application: /usr/bin/root.exe
// By ROOT version 6.24/06 on 2021-11-08 18:09:48

#if !defined( __CINT__) || defined (__MAKECINT__)

#ifndef ROOT_TStyle
#include "TStyle.h"
#endif

#endif

void Style_hist_grid_15_ticks()
{
   // Add the saved style to the current ROOT session.

   delete gROOT->GetStyle("hist_grid_15_ticks");

   TStyle *tmpStyle = new TStyle("hist_grid_15_ticks", "");
   tmpStyle->SetNdivisions(115, "x");
   tmpStyle->SetNdivisions(510, "y");
   tmpStyle->SetNdivisions(510, "z");
   tmpStyle->SetAxisColor(1, "x");
   tmpStyle->SetAxisColor(1, "y");
   tmpStyle->SetAxisColor(1, "z");
   tmpStyle->SetLabelColor(1, "x");
   tmpStyle->SetLabelColor(1, "y");
   tmpStyle->SetLabelColor(1, "z");
   tmpStyle->SetLabelFont(42, "x");
   tmpStyle->SetLabelFont(42, "y");
   tmpStyle->SetLabelFont(42, "z");
   tmpStyle->SetLabelOffset(0.005, "x");
   tmpStyle->SetLabelOffset(0.005, "y");
   tmpStyle->SetLabelOffset(0.005, "z");
   tmpStyle->SetLabelSize(0.035, "x");
   tmpStyle->SetLabelSize(0.035, "y");
   tmpStyle->SetLabelSize(0.035, "z");
   tmpStyle->SetTickLength(0.03, "x");
   tmpStyle->SetTickLength(0.03, "y");
   tmpStyle->SetTickLength(0.03, "z");
   tmpStyle->SetTitleOffset(1, "x");
   tmpStyle->SetTitleOffset(0, "y");
   tmpStyle->SetTitleOffset(1, "z");
   tmpStyle->SetTitleSize(0.035, "x");
   tmpStyle->SetTitleSize(0.035, "y");
   tmpStyle->SetTitleSize(0.035, "z");
   tmpStyle->SetTitleColor(1, "x");
   tmpStyle->SetTitleColor(1, "y");
   tmpStyle->SetTitleColor(1, "z");
   tmpStyle->SetTitleFont(42, "x");
   tmpStyle->SetTitleFont(42, "y");
   tmpStyle->SetTitleFont(42, "z");
   tmpStyle->SetBarWidth(1);
   tmpStyle->SetBarOffset(0.96);
   tmpStyle->SetDrawBorder(0);
   tmpStyle->SetOptLogx(0);
   tmpStyle->SetOptLogy(0);
   tmpStyle->SetOptLogz(0);
   tmpStyle->SetOptDate(0);
   tmpStyle->SetOptStat(10);
   tmpStyle->SetOptTitle(kTRUE);
   tmpStyle->SetOptFit(0);
   tmpStyle->SetNumberContours(20);
   tmpStyle->GetAttDate()->SetTextFont(62);
   tmpStyle->GetAttDate()->SetTextSize(0.025);
   tmpStyle->GetAttDate()->SetTextAngle(0);
   tmpStyle->GetAttDate()->SetTextAlign(11);
   tmpStyle->GetAttDate()->SetTextColor(1);
   tmpStyle->SetDateX(0.01);
   tmpStyle->SetDateY(0.01);
   tmpStyle->SetEndErrorSize(2);
   tmpStyle->SetErrorX(0.5);
   tmpStyle->SetFuncColor(2);
   tmpStyle->SetFuncStyle(1);
   tmpStyle->SetFuncWidth(2);
   tmpStyle->SetGridColor(0);
   tmpStyle->SetGridStyle(3);
   tmpStyle->SetGridWidth(1);
   tmpStyle->SetLegendBorderSize(1);
   tmpStyle->SetLegendFillColor(0);
   tmpStyle->SetLegendFont(42);
   tmpStyle->SetLegendTextSize(0);
   tmpStyle->SetHatchesLineWidth(1);
   tmpStyle->SetHatchesSpacing(1);
   tmpStyle->SetFrameFillColor(0);
   tmpStyle->SetFrameLineColor(1);
   tmpStyle->SetFrameFillStyle(1001);
   tmpStyle->SetFrameLineStyle(1);
   tmpStyle->SetFrameLineWidth(1);
   tmpStyle->SetFrameBorderSize(1);
   tmpStyle->SetFrameBorderMode(0);
   tmpStyle->SetHistFillColor(0);
   tmpStyle->SetHistLineColor(602);
   tmpStyle->SetHistFillStyle(1001);
   tmpStyle->SetHistLineStyle(1);
   tmpStyle->SetHistLineWidth(1);
   tmpStyle->SetHistMinimumZero(kFALSE);
   tmpStyle->SetCanvasPreferGL(kFALSE);
   tmpStyle->SetCanvasColor(0);
   tmpStyle->SetCanvasBorderSize(2);
   tmpStyle->SetCanvasBorderMode(0);
   tmpStyle->SetCanvasDefH(500);
   tmpStyle->SetCanvasDefW(700);
   tmpStyle->SetCanvasDefX(10);
   tmpStyle->SetCanvasDefY(10);
   tmpStyle->SetPadColor(0);
   tmpStyle->SetPadBorderSize(2);
   tmpStyle->SetPadBorderMode(0);
   tmpStyle->SetPadBottomMargin(0.1);
   tmpStyle->SetPadTopMargin(0.1);
   tmpStyle->SetPadLeftMargin(0.1);
   tmpStyle->SetPadRightMargin(0.1);
   tmpStyle->SetPadGridX(kTRUE);
   tmpStyle->SetPadGridY(kFALSE);
   tmpStyle->SetPadTickX(0);
   tmpStyle->SetPadTickY(0);
   tmpStyle->SetPaperSize(20, 26);
   tmpStyle->SetScreenFactor(1);
   tmpStyle->SetStatColor(0);
   tmpStyle->SetStatTextColor(1);
   tmpStyle->SetStatBorderSize(1);
   tmpStyle->SetStatFont(42);
   tmpStyle->SetStatFontSize(0);
   tmpStyle->SetStatStyle(1001);
   tmpStyle->SetStatFormat("6.4g");
   tmpStyle->SetStatX(0.98);
   tmpStyle->SetStatY(0.935);
   tmpStyle->SetStatW(0.2);
   tmpStyle->SetStatH(0.16);
   tmpStyle->SetStripDecimals(kTRUE);
   tmpStyle->SetTitleAlign(23);
   tmpStyle->SetTitleFillColor(0);
   tmpStyle->SetTitleTextColor(1);
   tmpStyle->SetTitleBorderSize(0);
   tmpStyle->SetTitleFont(42);
   tmpStyle->SetTitleFontSize(0.05);
   tmpStyle->SetTitleStyle(0);
   tmpStyle->SetTitleX(0.5);
   tmpStyle->SetTitleY(0.995);
   tmpStyle->SetTitleW(0);
   tmpStyle->SetTitleH(0);
   tmpStyle->SetLegoInnerR(0.5);

   Int_t fPaletteColor[255] = {924, 925, 926, 927, 928, 929, 930, 931, 932, 
                             933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 
                             943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 
                             953, 954, 955, 956, 957, 958, 959, 960, 961, 962, 
                             963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 
                             973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 
                             983, 984, 985, 986, 987, 988, 989, 990, 991, 992, 
                             993, 994, 995, 996, 997, 998, 999, 1000, 1001, 1002, 
                             1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 
                             1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 
                             1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 
                             1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 
                             1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 
                             1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 
                             1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 
                             1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 
                             1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 
                             1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 
                             1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 
                             1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120, 1121, 1122, 
                             1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 
                             1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 
                             1143, 1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 
                             1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 
                             1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172, 
                             1173, 1174, 1175, 1176, 1177, 1178};
   tmpStyle->SetPalette(255, fPaletteColor);

   TString fLineStyleArrayTmp[30] = {"", "  ", " 12 12", " 4 8", 
                             " 12 16 4 16", " 20 12 4 12", " 20 12 4 12 4 12 4 12", " 20 20", " 20 12 4 12 4 12", 
                             " 80 20", " 80 40 4 40", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", "  "};
   for (Int_t i=0; i<30; i++)
      tmpStyle->SetLineStyleString(i, fLineStyleArrayTmp[i]);

   tmpStyle->SetHeaderPS("");
   tmpStyle->SetTitlePS("");
   tmpStyle->SetFitFormat("5.4g");
   tmpStyle->SetPaintTextFormat("g");
   tmpStyle->SetLineScalePS(3);
   tmpStyle->SetJoinLinePS(0);
   tmpStyle->SetCapLinePS(0);
   tmpStyle->SetColorModelPS(0);
   tmpStyle->SetTimeOffset(788918400);

   tmpStyle->SetLineColor(1);
   tmpStyle->SetLineStyle(1);
   tmpStyle->SetLineWidth(1);
   tmpStyle->SetFillColor(19);
   tmpStyle->SetFillStyle(1001);
   tmpStyle->SetMarkerColor(1);
   tmpStyle->SetMarkerSize(1);
   tmpStyle->SetMarkerStyle(1);
   tmpStyle->SetTextAlign(11);
   tmpStyle->SetTextAngle(0);
   tmpStyle->SetTextColor(1);
   tmpStyle->SetTextFont(62);
   tmpStyle->SetTextSize(0.05);
}
