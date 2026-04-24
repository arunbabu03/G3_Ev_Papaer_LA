{
gStyle->SetOptStat(0);
gStyle->SetPalette(kRainBow); 



TFile *f1 = new TFile("Hist_20GeV.root");
TH2F *h1 = (TH2F*) f1->Get("histXZP");

TFile *f2 = new TFile("Hist_p5_20GeV.root");
TH2F *h2 = (TH2F*) f2->Get("histXZP");

TFile *f3 = new TFile("Hist_n5_20GeV.root");
TH2F *h3 = (TH2F*) f3->Get("histXZP");

h1->GetYaxis()->SetRangeUser(-0.1,0.1);
h2->GetYaxis()->SetRangeUser(-0.1,0.1);
h3->GetYaxis()->SetRangeUser(-0.1,0.1);

double zmin = min({h1->GetMinimum(), h2->GetMinimum(), h3->GetMinimum()});
double zmax = max({h1->GetMaximum(), h2->GetMaximum(), h3->GetMaximum()});

h1->SetMinimum(zmin); h1->SetMaximum(zmax);
h2->SetMinimum(zmin); h2->SetMaximum(zmax);
h3->SetMinimum(zmin); h3->SetMaximum(zmax);

TCanvas *c = new TCanvas("c","",2400,3600);
//c->Divide(1,3,0);
h1->SetTitle("");
h2->SetTitle("");
h3->SetTitle("");
h1->Scale(1/80.0);
h2->Scale(1/80.0);
h3->Scale(1/80.0);

h1->GetXaxis()->SetTickLength(-0.05);
h2->GetXaxis()->SetTickLength(-0.05);
h3->GetXaxis()->SetTickLength(-0.05);
h1->GetZaxis()->SetTickLength(-0.03);
h2->GetZaxis()->SetTickLength(-0.03);
h3->GetZaxis()->SetTickLength(-0.03);
h1->GetZaxis()->SetNdivisions(510);
h2->GetZaxis()->SetNdivisions(510);
h3->GetZaxis()->SetNdivisions(510);

h1->GetZaxis()->SetRangeUser(0,100);
h2->GetZaxis()->SetRangeUser(0,100);
h3->GetZaxis()->SetRangeUser(0,100);

h1->GetZaxis()->SetTitleFont(32);
h1->GetZaxis()->SetLabelFont(32);

h2->GetZaxis()->SetTitleFont(32);
h2->GetZaxis()->SetLabelFont(32);

h3->GetZaxis()->SetTitleFont(32);
h3->GetZaxis()->SetLabelFont(32);

h3->GetXaxis()->SetTitleFont(32);
h3->GetXaxis()->SetLabelFont(32);

h1->GetZaxis()->SetTitleOffset(0.3);
h1->GetZaxis()->SetTitleSize(0.1);
h1->GetZaxis()->SetLabelSize(0.08);
h1->GetZaxis()->SetLabelOffset(0.08);

h2->GetZaxis()->SetTitleOffset(0.3);
h2->GetZaxis()->SetTitleSize(0.1);
h2->GetZaxis()->SetLabelSize(0.08);
h2->GetZaxis()->SetLabelOffset(0.08);

h3->GetZaxis()->SetTitleOffset(0.3);
h3->GetZaxis()->SetTitleSize(0.1);
h3->GetZaxis()->SetLabelSize(0.08);
h3->GetZaxis()->SetLabelOffset(0.08);

h3->GetXaxis()->SetTitleOffset(0.3);
h3->GetXaxis()->SetTitleSize(0.1);
h1->GetXaxis()->SetLabelSize(0.0);
h2->GetXaxis()->SetLabelSize(0.0);
h3->GetXaxis()->SetLabelSize(0.08);
h3->GetXaxis()->SetLabelOffset(-0.03);
h3->GetXaxis()->SetTitle("");

h1->GetZaxis()->SetTitle("Axial Flux (arb.unit)");
h2->GetZaxis()->SetTitle("Axial Flux (arb.unit)");
h3->GetZaxis()->SetTitle("Axial Flux (arb.unit)");

// Title 
c->cd();  // go to full canvas
/*TPad *P1 = new TPad("P1","",0.0,0.95,1,1);
P1->SetFillStyle(4000);
P1->SetFrameFillStyle(0);
P1->Draw();
P1->cd();

TLatex *title = new TLatex();
title->SetNDC();
title->SetTextFont(32);   // bold
title->SetTextSize(0.50);
title->SetTextAlign(22);  // center alignment
title->DrawLatex(0.5, 0.5, "For 20 GeV Particles");*/

   TPad *P1 = new TPad("P1", "",0,0.95,1,1);
   P1->Draw();
   P1->cd();
   P1->Range(0,0,1,1);
   P1->SetFillColor(0);
   P1->SetFillStyle(4000);
   P1->SetBorderMode(0);
   P1->SetBorderSize(2);
   P1->SetFrameFillStyle(0);
   P1->SetFrameBorderMode(0);
   TLatex *tex = new TLatex(0.5,0.5,"For 20 GeV Particles");
   tex->SetNDC();
   tex->SetTextAlign(22);
   tex->SetTextFont(32);
   tex->SetTextSize(0.8);
   tex->SetLineWidth(2);
   tex->Draw();
   P1->Modified();
   c->cd();
   
    TPad *P2 = new TPad("P2", "",0,0.0,1,0.05);
   P2->Draw();
   P2->cd();
   P2->Range(0,0,1,1);
   P2->SetFillColor(0);
   P2->SetFillStyle(4000);
   P2->SetBorderMode(0);
   P2->SetBorderSize(2);
   P2->SetFrameFillStyle(0);
   P2->SetFrameBorderMode(0);
   TLatex *texx = new TLatex(0.5,0.5,"X Position");
   texx->SetNDC();
   texx->SetTextAlign(22);
   texx->SetTextFont(32);
   texx->SetTextSize(0.7);
   texx->SetLineWidth(2);
   texx->Draw();
   P2->Modified();
   c->cd();

/*c->cd();  // go to full canvas
TPad *P2 = new TPad("P1","",0.0,0.0,1,0.05);
P2->SetFillStyle(4000);
P2->SetFrameFillStyle(0);
P2->Draw();
P2->cd();

TLatex *xtitle = new TLatex();
xtitle->SetNDC();
xtitle->SetTextFont(132);   // Times Bold Italic
xtitle->SetTextSize(0.50);  // 0.50 is too large; typical is ~0.04–0.06
xtitle->SetTextAlign(22);   // center alignment
xtitle->DrawLatex(0.5, 0.5, "X Position");*/



c->cd();  // go to full canvas
TPad *P3 = new TPad("P1","",0.0,0.05,1,0.97);
P3->SetFillStyle(4000);
P3->SetFrameFillStyle(0);
P3->Draw();
P3->cd();

P3->Divide(1,3,0);
// Create TLatex for labels
TLatex *tex1 = new TLatex();
tex1->SetNDC();          // Use normalized coordinates
tex1->SetTextSize(0.06);
tex1->SetTextAlign(22);
tex1->SetTextFont(32);
   tex1->SetTextSize(0.08);
   tex1->SetLineWidth(2);

// -------- Panel 1 --------
P3->cd(1);
gPad->SetTheta(0);
gPad->SetPhi(0);
h1->Draw("surf2");


tex1->DrawLatex(0.8, 0.8, "Without Rotation");

// -------- Panel 2 --------
P3->cd(2);
gPad->SetTheta(0);
gPad->SetPhi(0);
h2->Draw("surf2");
tex1->DrawLatex(0.8, 0.8, "With +5^{#circ} Rotation ");

// -------- Panel 3 --------
P3->cd(3);
gPad->SetTheta(0);
gPad->SetPhi(0);
h3->Draw("surf2");
tex1->DrawLatex(0.8, 0.8, "With -5^{#circ} Rotation ");

c->SaveAs("Com_F.pdf");
}
