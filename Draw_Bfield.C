{
gStyle->SetOptStat(0);
gStyle->SetPalette(kRainbow);

TFile *fr = new TFile("B_Data.root");

TH2F *Bx=(TH2F*) fr->Get("Bx2D");
TH2F *By=(TH2F*) fr->Get("By2D");
TH2F *Bz=(TH2F*) fr->Get("Bz2D"); 

Bx->SetMaximum(45);
Bx->SetMinimum(-45);
By->SetMaximum(45);
By->SetMinimum(-45);
Bz->SetMaximum(45);
Bz->SetMinimum(-45);

Bx->GetXaxis()->SetNdivisions(508); 
By->GetXaxis()->SetNdivisions(508); 
Bz->GetXaxis()->SetNdivisions(508); 
Bx->GetYaxis()->SetNdivisions(508); 
By->GetYaxis()->SetNdivisions(508); 
Bz->GetYaxis()->SetNdivisions(508); 

Bx->GetXaxis()->CenterTitle(true);
By->GetXaxis()->CenterTitle(true);
Bz->GetXaxis()->CenterTitle(true);
Bx->GetYaxis()->CenterTitle(true);
By->GetYaxis()->CenterTitle(true);
Bz->GetYaxis()->CenterTitle(true);


Bx->SetTitleFont(32);
By->SetTitleFont(32);
Bz->SetTitleFont(32);

Bx->GetYaxis()->SetTitleFont(32);
Bx->GetYaxis()->SetLabelFont(32);
By->GetYaxis()->SetTitleFont(32);
By->GetYaxis()->SetLabelFont(32);
Bz->GetYaxis()->SetTitleFont(32);
Bz->GetYaxis()->SetLabelFont(32);
Bx->GetXaxis()->SetTitleFont(32);
Bx->GetXaxis()->SetLabelFont(32);
By->GetXaxis()->SetTitleFont(32);
By->GetXaxis()->SetLabelFont(32);
Bz->GetXaxis()->SetTitleFont(32);
Bz->GetXaxis()->SetLabelFont(32);
Bz->GetZaxis()->SetTitleFont(32);
Bz->GetZaxis()->SetLabelFont(32);

Bx->GetXaxis()->SetTitleOffset(0.8);
Bx->GetXaxis()->SetTitleSize(0.05);
Bx->GetXaxis()->SetLabelSize(0.03);
Bx->GetXaxis()->SetLabelOffset(0.01);
Bx->GetYaxis()->SetTitleOffset(0.8);
Bx->GetYaxis()->SetTitleSize(0.05);
Bx->GetYaxis()->SetLabelSize(0.03);
Bx->GetYaxis()->SetLabelOffset(0.01);

By->GetXaxis()->SetTitleOffset(0.8);
By->GetXaxis()->SetTitleSize(0.05);
By->GetXaxis()->SetLabelSize(0.03);
By->GetXaxis()->SetLabelOffset(0.01);
By->GetYaxis()->SetTitleOffset(0.8);
By->GetYaxis()->SetTitleSize(0.05);
By->GetYaxis()->SetLabelSize(0.03);
By->GetYaxis()->SetLabelOffset(0.01);

Bz->GetXaxis()->SetTitleOffset(0.8);
Bz->GetXaxis()->SetTitleSize(0.05);
Bz->GetXaxis()->SetLabelSize(0.03);
Bz->GetXaxis()->SetLabelOffset(0.01);
Bz->GetYaxis()->SetTitleOffset(0.8);
Bz->GetYaxis()->SetTitleSize(0.05);
Bz->GetYaxis()->SetLabelSize(0.03);
Bz->GetYaxis()->SetLabelOffset(0.01);

TCanvas *c = new TCanvas("c", "", 800, 2400);
/*c->Divide(2,3,0);
c->cd(1);
Bx->Draw();
c->cd(3);
By->Draw();
c->cd(5);
Bz->Draw();

c->cd(2);
Bx->Draw("surf2");
c->cd(4);
By->Draw("surf2");
c->cd(6);
Bz->Draw("surf2");*/

TPad *P1 = new TPad("P1","",0.01,0.0,0.33,1);
P1->SetFillStyle(4000);
P1->SetFrameFillStyle(0);
P1->Draw();
P1->cd();
Bx->Draw();

c->cd();
TPad *P2 = new TPad("P2","",0.33,0.0,0.65,1);
P2->SetFillStyle(4000);
P2->SetFrameFillStyle(0);
P2->Draw();
P2->cd();
By->Draw();

c->cd();
TPad *P3 = new TPad("P3","",0.66,0.0,1,1);
P3->SetFillStyle(4000);
P3->SetFrameFillStyle(0);
P3->Draw();
P3->cd();
Bz->Draw("colz");

}
