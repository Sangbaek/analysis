// ROOT
#include <TStyle.h>

// runMonitor
#include "utils.h"

void setStyle()
{
	double run[N];

	cout << " Setting ROOT Style..." << endl;
	
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetFrameBorderMode(0);
	gStyle->SetPadBorderMode(0);
	
	gStyle->SetPadTopMargin(0.16);
	gStyle->SetPadBottomMargin(0.14);
	gStyle->SetPadLeftMargin(0.18);
	
	gStyle->SetTitleFont(13);
	gStyle->SetTitleColor(2);
	
	gStyle->SetLabelOffset(0.02,"XY");
	gStyle->SetTitleSize(0.044,"XY");
	gStyle->SetTitleOffset(1.5,"XY");
	
	gStyle->SetLabelFont(13,"xy"); //use font 1 precision 3
	gStyle->SetLabelSize(14, "xy"); //set label size in pixels
	
	gStyle->SetCanvasColor(19);
	gStyle->SetPadColor(19);
}

