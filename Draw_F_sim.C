{
gStyle->SetOptStat(0);
TFile *f = new TFile("SimDat.root");
gStyle->SetPalette(kRainBow); 
TH2F *h1 = (TH2F*) f->Get("All_P_histXZ");

TH2F *h2 = (TH2F*) h1->Clone("All_P_histXZ_C");



h1->SetTitle("");
h2->SetTitle("");
h2->GetZaxis()->SetTitle("Axial Flux (arb.unit)");

h1->GetXaxis()->CenterTitle(true);
h2->GetXaxis()->CenterTitle(true);
h1->GetYaxis()->CenterTitle(true);
h2->GetZaxis()->CenterTitle(true);
//h1->GetXaxis()->SetTickLength(-0.05);
h2->GetXaxis()->SetTickLength(-0.05); 
//h1->GetYaxis()->SetTickLength(-0.05);
h2->GetZaxis()->SetTickLength(-0.05); 
h1->GetZaxis()->SetNdivisions(510);
h2->GetZaxis()->SetNdivisions(510); 

h1->GetXaxis()->SetTitleFont(32);
h1->GetXaxis()->SetLabelFont(32);
h2->GetXaxis()->SetTitleFont(32);
h2->GetXaxis()->SetLabelFont(32);
h1->GetZaxis()->SetTitleFont(32);
h1->GetZaxis()->SetLabelFont(32);
h2->GetZaxis()->SetTitleFont(32);
h2->GetZaxis()->SetLabelFont(32);
h1->GetYaxis()->SetTitleFont(32);
h1->GetYaxis()->SetLabelFont(32);
h2->GetYaxis()->SetTitleFont(32);
h2->GetYaxis()->SetLabelFont(32);

h1->GetYaxis()->SetTitleOffset(0.8);
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetLabelSize(0.03);
h1->GetYaxis()->SetLabelOffset(0.01);

h1->GetZaxis()->SetTitleOffset(0.8);
h1->GetZaxis()->SetTitleSize(0.05);
h1->GetZaxis()->SetLabelSize(0.03);
h1->GetZaxis()->SetLabelOffset(0.01);

h1->GetXaxis()->SetTitleOffset(0.65);
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.03);
h1->GetXaxis()->SetLabelOffset(0.01);


h2->GetZaxis()->SetTitleOffset(0.8);
h2->GetZaxis()->SetTitleSize(0.05);
h2->GetZaxis()->SetLabelSize(0.03);
h2->GetZaxis()->SetLabelOffset(0.1);

h2->GetXaxis()->SetTitleOffset(0.65);
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetLabelSize(0.03);
h2->GetXaxis()->SetLabelOffset(-0.01);

TCanvas *c = new TCanvas("c","",3600,1800);
c->Divide(2,1);

c->cd(1);
h1->Draw("colz");
h1->SetTitle("");

 

c->cd(2);

h2->GetYaxis()->SetRangeUser(-0.1,0.1);
gPad->SetTheta(0);            // Elevation angle
gPad->SetPhi(0);  
h2->Draw("surf2");
h2->SetTitle("");

 

c->SaveAs("Fig_NS.eps");

}
