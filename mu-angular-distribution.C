
TCanvas* graph()
{
//   gStyle->SetOptStat(0);
//   gStyle->SetOptFit();

//    TCanvas *c = new TCanvas("c","Track length shortlived particle",0,0,1000,1000);
//      TCanvas *c = new TCanvas("c"," H tracks Parameters  ",0,0,1200,1000); 
         TCanvas *c = new TCanvas("c"," cos  cos**2 primers ",0,0,800,600);


//   c->Divide(2,1);
   Int_t nlines = 0,  nev;
   Float_t e;
//   Double_t tr_len;
     Double_t alfa, pii=3.14159265;
 
TLegend *legend = new TLegend(.68,.58,.88,.76);

 
  Int_t i,nsob = 0, npart, np_=0, npi_=0, neta_=0, nmu_part; 
  //Int_t ntr, npoint; 
  // Double_t nn, f1,f2,fii;
  //Double_t  mpart, px, py,pz,ee,eta_part,eta_part1,ptot22,ptrans;

 Double_t Nev, pant, xx, yy, zz, Ekin, pxx, pyy, pzz, PPHC, tr, mpid, Nlev; 

Double_t teta_Z;
 
//
  Double_t x[2]={0.0, 0.02},y[2]={0.0,1200.0};   
 
   ifstream in; 

  // ofstream im;
  



//  ********************************************************************

//   c->cd(1);

   TGraph*g0 = new TGraph(2,x,y);

 // g0->SetTitle("Muons angluar distribution for 10 GeV, emstandard_opt0 "); 
 //   g0->SetTitle("Muons angluar distribution for 10 GeV, emstandard_opt4 ");   
   // g0->SetTitle("Muons angluar distribution for 10 GeV, emstandardWVI ");   
  //   g0->SetTitle("Muons angluar distribution for 80 GeV, emstandard_opt4, set_cut 0.1 cm ");  
  g0->SetTitle("Muons angluar distribution for 150 GeV, emstandard_opt4, set_cut 0.5 cm ");
          
 
   g0->GetXaxis()->SetTitle("#theta_{z}, Rad");         


   g0->GetXaxis()->SetLabelSize(0.030);
//   g0->GetXaxis()->SetNdivisions(205);
   g0->GetXaxis()->SetNdivisions(414);   
   g0->GetYaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetYaxis()->SetNdivisions(414);    
   g0->Draw("AP");





TH1F *h1 = new TH1F("h1","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h2 = new TH1F("h2","mu=150GeV", 100, 0.0, 0.02)  ;
TH1F *h3 = new TH1F("h3","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h4 = new TH1F("h4","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h5 = new TH1F("h5","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h6 = new TH1F("h6","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h7 = new TH1F("h7","mu=150GeV", 100, 0.0, 0.02);
TH1F *h8 = new TH1F("h8","mu=150GeV", 100, 0.0, 0.02) ;
TH1F *h9 = new TH1F("h9","mu=150GeV",  100, 0.0, 0.02) ;
TH1F *h10 = new TH1F("h10","mu=150GeV", 100, 0.0, 0.02) ;



   nlines = 0;

  in.open("mu-trec-info-1GeV-opt4-0-1cm");
    //  in.open("10GeV-optWVI-mu-tracks");
 //  in.open("10GeV-opt4-mu-tracks"); 
//   in.open("10GeV-opt0-mu-tracks"); 
   while(1) {
 
  in >> Nev >> Nlev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 


teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;
if (Nlev == 1) h1 -> Fill(teta_Z);
 if (Nlev == 2) h2 -> Fill(teta_Z);
 if (Nlev == 3)  h3 -> Fill(teta_Z);
 if (Nlev == 4) h4 -> Fill(teta_Z);
 if (Nlev == 5) h5 -> Fill(teta_Z);
 if (Nlev == 6) h6 -> Fill(teta_Z);
 if (Nlev == 7) h7 -> Fill(teta_Z);
 if (Nlev == 8) h8 -> Fill(teta_Z);
 if (Nlev == 9) h9 -> Fill(teta_Z);
 if (Nlev == 10) h10 -> Fill(teta_Z);




   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

//-----------------------------------

      

//   h1->SetFillColor(kGreen);
 h1->SetLineColor(kBlue);  
//    h1->SetLineColor(kCyan);
h1->SetLineWidth(3);
 legend->AddEntry(h1,"Fe - 60cm");
   h1->Draw("sames");

  

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
 h2->SetLineColor(kGreen+1);  
//    h1->SetLineColor(kCyan);
 h2->SetLineWidth(3);
 legend->AddEntry(h2,"Fe - 300cm ");
   h2->Draw("sames");

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
 //h3->SetLineColor(kCyan+2);  
 h3->SetLineColor(kOrange-3); 
 h3->SetLineWidth(3);
 legend->AddEntry(h3,"Fe - 600cm ");
   h3->Draw("sames");

//-----

 h4->SetLineColor(kRed+1); 
 h4->SetLineWidth(3);
 legend->AddEntry(h4,"Fe - 900cm ");
   h4->Draw("sames");

//------

h5->SetLineColor(kYellow+3); 
 h5->SetLineWidth(3);
 legend->AddEntry(h5,"Fe - 1200cm ");
   h5->Draw("sames");

//----------- 

   h6->SetLineColor(kCyan+2); 
 h6->SetLineWidth(3);
 legend->AddEntry(h6,"Fe - 1500cm ");
   h6->Draw("sames");

//-----

h7->SetLineColor(kBlue+4); 
 h7->SetLineWidth(3);
 legend->AddEntry(h7,"Fe - 1800cm ");
   h7->Draw("sames");

   //------------

h8->SetLineColor(kPink-8); 
 h8->SetLineWidth(3);
 legend->AddEntry(h8,"Fe - 2100cm ");
   h8->Draw("sames");

//---------

h9->SetLineColor(kViolet+7); 
 h9->SetLineWidth(3);
 legend->AddEntry(h9,"Fe - 2400cm ");
   h9->Draw("sames");

//------

h10->SetLineColor(kAzure-4); 
 h10->SetLineWidth(3);
 legend->AddEntry(h10,"Fe - 2700cm ");
   h10->Draw("sames"); 









legend->Draw();

/*  auto ix1 = new TGraph();
  auto ix2 = new TGraph(); 

  ix1 -> SetPoint(1,7.2,0.0);
  ix1 -> SetPoint(2,7.2,700000 ); 

  ix2 -> SetPoint(1,8.6,0.0); 
  ix2 -> SetPoint(2,8.6,700000 );   

   ix1->SetLineWidth(2);
   ix1->SetLineColor(49);
    ix1->Draw("LP");
   
   ix2->SetLineWidth(2);
   ix2->SetLineColor(49);
    ix2->Draw("LP");
*/    
 
   
   
   


   return c;
}
