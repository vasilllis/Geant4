
TCanvas* graph()
{
//   gStyle->SetOptStat(0);
//   gStyle->SetOptFit();

//    TCanvas *c = new TCanvas("c","Track length shortlived particle",0,0,1000,1000);
//      TCanvas *c = new TCanvas("c"," H tracks Parameters  ",0,0,1200,1000); 
         TCanvas *c = new TCanvas("c"," Track length ",0,0,800,600);


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

Double_t teta_Z,r;
 
//
 // Double_t x[2]={0.0, 0.16},y[2]={0.0,5000.0};   
  Double_t x[2]={0.0, 3000},y[2]={0.0,2000.0};
 
   ifstream in; 

  // ofstream im;
  



//  ********************************************************************

//   c->cd(1);

   TGraph*g0 = new TGraph(2,x,y);

 // g0->SetTitle("Muons angluar distribution for 10 GeV, emstandard_opt0 "); 
 //   g0->SetTitle("Muons angluar distribution for 10 GeV, emstandard_opt4 ");   
   // g0->SetTitle("Muons angluar distribution for 10 GeV, emstandardWVI ");   
  //   g0->SetTitle("Muons angluar distribution for 80 GeV, emstandard_opt4, set_cut 0.1 cm ");  
  g0->SetTitle("Muon single scattering point, emstandard_opt4, set_cut 0.5 cm ");
          
 
  // g0->GetXaxis()->SetTitle("#theta_{z}, Rad");  
   g0->GetXaxis()->SetTitle("zz, cm");       


   g0->GetXaxis()->SetLabelSize(0.030);
//   g0->GetXaxis()->SetNdivisions(205);
   g0->GetXaxis()->SetNdivisions(414);   
   g0->GetYaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetYaxis()->SetNdivisions(414);    
   g0->Draw("AP");




/*
TH1F *h1 = new TH1F("h1","", 100, 0.0, 0.2) ;
TH1F *h2 = new TH1F("h2","", 100, 0.0, 0.2) ;
TH1F *h3 = new TH1F("h3","", 100, 0.0, 0.2) ;
TH1F *h4 = new TH1F("h4","", 100, 0.0, 0.2) ; */
TH1F *h1 = new TH1F("h1","", 100, 0.0, 3000) ;
TH1F *h2 = new TH1F("h2","", 100, 0.0, 3000) ;
TH1F *h3 = new TH1F("h3","", 100, 0.0, 3000) ;
TH1F *h4 = new TH1F("h4","", 100, 0.0, 3000) ;




   nlines = 0;

  in.open("mu-scattering-info-10GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 


teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

//h1 -> Fill(teta_Z);
h1 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

//-----------------------------------

   nlines = 0;

  in.open("mu-scattering-info-50GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 


teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

//h2 -> Fill(teta_Z);
h2 -> Fill(zz);

   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();
   // -----------------------

   nlines = 0;

  in.open("mu-scattering-info-100GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 


teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

//h3 -> Fill(teta_Z);
h3 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

   //-----------------------

   nlines = 0;

  in.open("mu-scattering-info-150GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 


teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

//h4 -> Fill(teta_Z);
h4 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();




      

//   h1->SetFillColor(kGreen);
 h1->SetLineColor(kBlue);  
//    h1->SetLineColor(kCyan);
h1->SetLineWidth(3);
 legend->AddEntry(h1,"10GeV");
   h1->Draw("sames");
//------------
//   h1->SetFillColor(kGreen);
 h2->SetLineColor(kPink-8);  
//    h1->SetLineColor(kCyan);
h2->SetLineWidth(3);
 legend->AddEntry(h2,"50GeV");
   h2->Draw("sames");

//----------
//   h1->SetFillColor(kGreen);
 h3->SetLineColor(kGreen);  
//    h1->SetLineColor(kCyan);
h3->SetLineWidth(3);
 legend->AddEntry(h3,"100GeV");
   h3->Draw("sames");

   //-------------
  //   h1->SetFillColor(kGreen);
 h4->SetLineColor(kRed);  
//    h1->SetLineColor(kCyan);
h4->SetLineWidth(3);
 legend->AddEntry(h4,"150GeV");
   h4->Draw("sames"); 








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
