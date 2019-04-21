// ###########################################
//            Author: Dengfeng Zhang
// ###########################################
// local includes
#include "SetAttributes.h"
// if want to call following functions, do following
// from ROOT import *; gROOT.ProcessLine("#include \"HistToolKit.h\"")

int SetGraphDrawOption(TGraph *gr, bool isdrawline=true, bool isdrawbar=false, bool isrectangle=true)
{
  if(!isdrawline&&!isdrawbar)
  {  gr->Draw("AP") ; return 0 ;}
  if(isdrawline)
  {  gr->Draw("ALP") ; return 0 ;}
  if(isdrawbar)
    gr->Draw("AB") ;
  return 0 ;
}
int DrawSigleGraphOnCanvas(string canvasname, TGraph *gr, string drawoption="APL",
                   bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphAttributes(gr, 1, 2, 1, 1001, 1, 20, 1, 1) ;

  // draw graph
  gr-Draw(drawoption.c_str()) ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int DrawTwoGraphsOnCanvas(string canvasname, TGraph *gr1, TGraph *gr2, 
                   string drawoption1="APL", string drawoption2="PL",
                   bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  gStyle->SetOptTitle(0) ;
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphAttributes(gr1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAttributes(gr2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  gr1->Draw(drawoption1.c_str()) ;
  gr2->Draw(drawoption2.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(gr1, gr1->GetTitle(), "LP") ;
  leg->AddEntry(gr2, gr2->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int DrawFourGraphsOnCanvas(string canvasname, TGraph *gr1, TGraph *gr2, TGraph *gr3, TGraph *gr4,
string drawopt1="APL", string drawopt2="PL", string drawopt3="PL", string drawopt4="PL",
bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  gStyle->SetOptTitle(0) ;
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphAttributes(gr1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAttributes(gr2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  SetGraphAttributes(gr3, 1, 2, 3, 1001, 3, 23, 3, 1) ;
  SetGraphAttributes(gr4, 1, 2, 4, 1001, 4, 24, 4, 1) ;
  gr1->Draw(drawopt1.c_str()) ;
  gr2->Draw(drawopt2.c_str()) ;
  gr3->Draw(drawopt3.c_str()) ;
  gr4->Draw(drawopt4.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(gr1, gr1->GetTitle(), "LP") ;
  leg->AddEntry(gr2, gr2->GetTitle(), "LP") ;
  leg->AddEntry(gr3, gr3->GetTitle(), "LP") ;
  leg->AddEntry(gr4, gr4->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int DrawFiveGraphsOnCanvas(string canvasname, TGraph *gr1, TGraph *gr2, TGraph *gr3, TGraph *gr4,TGraph *gr5,
string drawopt1="APL", string drawopt2="PL", string drawopt3="PL", string drawopt4="PL", string drawopt5="PL", 
bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  gStyle->SetOptTitle(0) ;
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphAttributes(gr1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAttributes(gr2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  SetGraphAttributes(gr3, 1, 2, 3, 1001, 3, 23, 3, 1) ;
  SetGraphAttributes(gr4, 1, 2, 4, 1001, 4, 24, 4, 1) ;
  SetGraphAttributes(gr5, 1, 2, 5, 1001, 5, 25, 5, 1) ;
  gr1->Draw(drawopt1.c_str()) ;
  gr2->Draw(drawopt2.c_str()) ;
  gr3->Draw(drawopt3.c_str()) ;
  gr4->Draw(drawopt4.c_str()) ;
  gr5->Draw(drawopt5.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.5,0.4,0.89,0.89) ;
  leg->SetTextSize(0.03) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(gr1, gr1->GetTitle(), "LP") ;
  leg->AddEntry(gr2, gr2->GetTitle(), "LP") ;
  leg->AddEntry(gr3, gr3->GetTitle(), "LP") ;
  leg->AddEntry(gr4, gr4->GetTitle(), "LP") ;
  leg->AddEntry(gr5, gr5->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int SetGraphErrorsDrawOption(TGraphErrors *gre, bool isdrawline=true, bool isdrawerrorrectangle=false, bool isdrawerrorband=false)
{
  if(!isdrawline&&!isdrawerrorrectangle&&!isdrawerrorband)
  {  gre->Draw("AP") ; return 0 ;}
  if(isdrawline)
  {  gre->Draw("APL") ; return 0 ;}
  if(isdrawerrorrectangle)
  {
    gre->Draw("A2") ;
    gre->Draw("P") ;
    return 0 ;
  }
  if(isdrawerrorband)
  {
    gre->Draw("A3") ;
    gre->Draw("LX") ;
  }
  return 0 ;
}
int DrawSingleGraphErrorsOnCanvas(string canvasname, TGraphErrors *gre, string drawoption="APL",
                   bool logx=false, bool logy=false, 
                   bool isdrawerrorband=false,  bool isrectangle=true)
{
  gStyle->SetOptTitle(0);
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;

  // set options of grapherrors
  SetGraphErrorsAttributes(gre, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  gre->Draw(drawoption.c_str()) ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}
int DrawTwoGraphErrorsOnCanvas(string canvasname, TGraphErrors *gre1, TGraphErrors *gre2, string drawoption1="APL", string drawoption2="PL", bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  // define canvas
  gStyle->SetOptTitle(0);
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphErrorsAttributes(gre1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphErrorsAttributes(gre2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  gre1->Draw(drawoption1.c_str()) ;
  gre2->Draw(drawoption2.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(gre1, gre1->GetTitle(), "LEP") ;
  leg->AddEntry(gre2, gre2->GetTitle(), "LEP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}
int DrawThreeGraphErrorsOnCanvas(string canvasname, TGraphErrors *gre1, TGraphErrors *gre2, TGraphErrors *gre3, string drawoption1="AP", string drawoption2="P", string drawoption3="P", bool logx=false, bool logy=false, bool isrectangle=true)
{  // better not to set drawline or drawbar to be 1 at the same time
  // define canvas
  gStyle->SetOptTitle(0);
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;
  // set attributes of graph
  SetGraphErrorsAttributes(gre1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphErrorsAttributes(gre2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  SetGraphErrorsAttributes(gre3, 1, 2, 3, 1001, 3, 22, 3, 1) ;
  gre1->Draw(drawoption1.c_str()) ;
  gre2->Draw(drawoption2.c_str()) ;
  gre3->Draw(drawoption3.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(gre1, gre1->GetTitle(), "LEP") ;
  leg->AddEntry(gre2, gre2->GetTitle(), "LEP") ;
  leg->AddEntry(gre3, gre3->GetTitle(), "LEP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int SetGraphAsymmErrorsDrawOption(TGraphAsymmErrors *grae, bool isdrawline=true, bool isdrawerrorrectangle=false, bool isdrawerrorband=false)
{
  if(!isdrawline&&!isdrawerrorrectangle&&!isdrawerrorband)
  {  grae->Draw("AP") ; return 0 ;}
  if(isdrawline)
  {  grae->Draw("APL") ; return 0 ;}
  if(isdrawerrorrectangle)
  { 
    grae->Draw("A2") ;
    grae->Draw("P") ;
    return 0 ;
  }
  if(isdrawerrorband)
  { 
    grae->Draw("A3") ;
    grae->Draw("LX") ;
  }
  return 0 ;
}

int DrawSigleAsymmGraphErrorsOnCanvas(string canvasname, TGraphAsymmErrors *agre, string drawoption="APL",
                   bool logx=false, bool logy=false, bool isrectangle=true)
{
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;

  // set options of grapherror
  SetGraphAsymmErrorsAttributes(agre, 1, 2, 1, 1001, 1, 20, 1, 1) ;

  agre->Draw(drawoption.c_str()) ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}
int DrawTwoAsymmGraphErrorsOnCanvas(string canvasname, TGraphAsymmErrors *agre1, TGraphAsymmErrors *agre2,
string drawopt1="APL", string drawopt2="PL", bool logx=false, bool logy=false, bool isrectangle=true)
{
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;

  // set options of grapherror
  SetGraphAsymmErrorsAttributes(agre1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAsymmErrorsAttributes(agre2, 1, 2, 2, 1001, 2, 21, 2, 1) ;

  agre1->Draw(drawopt1.c_str()) ;
  agre2->Draw(drawopt2.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(agre1, agre1->GetTitle(), "LP") ;
  leg->AddEntry(agre2, agre2->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int DrawFourAsymmGraphErrorsOnCanvas(string canvasname, TGraphAsymmErrors *agre1, TGraphAsymmErrors *agre2,
TGraphAsymmErrors *agre3, TGraphAsymmErrors *agre4,
string drawopt1="APL", string drawopt2="PL", string drawopt3="PL", string drawopt4="PL",
bool logx=false, bool logy=false, bool isrectangle=true)
{
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;

  // set options of grapherror
  SetGraphAsymmErrorsAttributes(agre1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAsymmErrorsAttributes(agre2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  SetGraphAsymmErrorsAttributes(agre3, 1, 2, 3, 1001, 3, 22, 3, 1) ;
  SetGraphAsymmErrorsAttributes(agre4, 1, 2, 4, 1001, 4, 23, 4, 1) ;

  agre1->Draw(drawopt1.c_str()) ;
  agre2->Draw(drawopt2.c_str()) ;
  agre3->Draw(drawopt3.c_str()) ;
  agre4->Draw(drawopt4.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.55,0.65,0.89,0.89) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(agre1, agre1->GetTitle(), "LP") ;
  leg->AddEntry(agre2, agre2->GetTitle(), "LP") ;
  leg->AddEntry(agre3, agre3->GetTitle(), "LP") ;
  leg->AddEntry(agre4, agre4->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}

int DrawFiveAsymmGraphErrorsOnCanvas(string canvasname, TGraphAsymmErrors *agre1, TGraphAsymmErrors *agre2,
TGraphAsymmErrors *agre3, TGraphAsymmErrors *agre4, TGraphAsymmErrors *agre5,
string drawopt1="APL", string drawopt2="PL", string drawopt3="PL", string drawopt4="PL", string drawopt5="PL",
bool logx=false, bool logy=false, bool isrectangle=true)
{
  // define canvas
  float height = 600, width = 600 ;
  if(isrectangle)
    width = 800 ;
  TCanvas *c = new TCanvas(canvasname.c_str(), "", width, height) ;
  c->SetTickx() ;
  c->SetTicky() ;
  if(logx) c->SetLogx() ;
  if(logy) c->SetLogy() ;

  // set options of grapherror
  SetGraphAsymmErrorsAttributes(agre1, 1, 2, 1, 1001, 1, 20, 1, 1) ;
  SetGraphAsymmErrorsAttributes(agre2, 1, 2, 2, 1001, 2, 21, 2, 1) ;
  SetGraphAsymmErrorsAttributes(agre3, 1, 2, 3, 1001, 3, 22, 3, 1) ;
  SetGraphAsymmErrorsAttributes(agre4, 1, 2, 4, 1001, 4, 23, 4, 1) ;
  SetGraphAsymmErrorsAttributes(agre5, 1, 2, 5, 1001, 5, 24, 5, 1) ;

  agre1->Draw(drawopt1.c_str()) ;
  agre2->Draw(drawopt2.c_str()) ;
  agre3->Draw(drawopt3.c_str()) ;
  agre4->Draw(drawopt4.c_str()) ;
  agre5->Draw(drawopt5.c_str()) ;
  // draw TLegend
  TLegend *leg=new TLegend(0.5,0.4,0.89,0.89) ;
  leg->SetTextSize(0.03) ;
  leg->SetFillStyle(0) ;
  leg->SetBorderSize(0) ;
  leg->AddEntry(agre1, agre1->GetTitle(), "LP") ;
  leg->AddEntry(agre2, agre2->GetTitle(), "LP") ;
  leg->AddEntry(agre3, agre3->GetTitle(), "LP") ;
  leg->AddEntry(agre4, agre4->GetTitle(), "LP") ;
  leg->AddEntry(agre5, agre5->GetTitle(), "LP") ;
  leg->Draw("same") ;
  c->Print((canvasname+".eps").c_str()) ;
  return 0 ;
}
