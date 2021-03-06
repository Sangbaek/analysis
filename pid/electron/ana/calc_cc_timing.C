void calc_cc_timing()
{
	gStyle->SetPadLeftMargin(0.1);
	gStyle->SetPadRightMargin(0.12);
	gStyle->SetPadTopMargin(0.12);
	gStyle->SetPadBottomMargin(0.14);
		
	TLatex lab;
	lab.SetNDC();
	
	TCanvas *Ccc_timing  = new TCanvas("Ccc_timing", "Ccc_timing", 800, 800);

	
	int s = SECTOR - 1;
	double xb[36], xbe[36], ybe[36];
	for(int b=0; b<36; b++)
	{
		xb[b]  = b+1.5;
		xbe[b] = 0.5;
		ybe[b] = 0;
	}


	// reading cuts from original pass - looks like about 5 sigma was saved
	// reading those values instead of re-doing the fit, which may yield slightly different results
	// and confuse people.
	// alternatively, I could re-run all the DST with slightly different cuts

//	// Slicing + fitting
	cout << " Fitting sector " << s+1 << endl;
	for(int b=0; b<36; b++)
	{
		cerr << " Fitting pmt " << b+1 << endl;
		H.cc_timing[1][s]->ProjectionY(Form("cc_timing1d_s%d_pmt%d", s+1, b+1), b+2, b+3);
		cc_timing1d[s][b] = (TH1F*)gROOT->Get(Form("cc_timing1d_s%d_pmt%d", s+1, b+1));
		
		// Gaussian fit
		cc_timing1d[s][b]->Fit("gaus", "QEM");
		cout << "  N. events: " << cc_timing1d[s][b]->Integral() << endl;
		if(cc_timing1d[s][b]->Integral() > 0)
		{
			double mean  = cc_timing1d[s][b]->GetFunction("gaus")->GetParameter(1);
			double sigma = cc_timing1d[s][b]->GetFunction("gaus")->GetParameter(2);
			cc_timing1d[s][b]->GetFunction("gaus")->SetLineWidth(2);
			cc_timing1d[s][b]->GetFunction("gaus")->SetLineColor(kRed+3);
			
			Pars.cc_timing_low[s][b] = mean - Pars.CC_T_NSIGMAS*sigma;
			if(fabs(mean - Pars.CC_T_NSIGMAS*sigma) > 20 )Pars.cc_timing_low[s][b] = -100.0;
			
		}
	}

	cc_timing_low[s] = new TGraphErrors(36, xb, Pars.cc_timing_low[s], xbe, ybe);
	cc_timing_low[s]->SetMarkerSize(0.2);
	cc_timing_low[s]->SetLineWidth(2);

	cout << " done " << endl;
	Ccc_timing->Close();
	
}


void calc_all_cc_timing()
{
	for(int s=0; s<6; s++)
	{
		SECTOR = s+1;
		calc_cc_timing();
	}
	SECTOR = 1;
}


















