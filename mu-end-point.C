
TCanvas* graph()
{
//   gStyle->SetOptStat(0);
//   gStyle->SetOptFit();
gStyle -> SetPalette(0);
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
  Double_t x[2]={0.0, 3000},y[2]={0.0,20.0};   
 
   ifstream in; 

  // ofstream im;
  



//  ********************************************************************

//   c->cd(1);

   TGraph*g0 = new TGraph(2,x,y);

  
  g0->SetTitle("End-points for muouns in 30 meters, emstandard_opt4, set_cut 0.5 cm ");
   g0->GetXaxis()->SetTitle("zz, cm");         
   g0->GetXaxis()->SetLabelSize(0.030);
//   g0->GetXaxis()->SetNdivisions(205);
   g0->GetXaxis()->SetNdivisions(414);   
   g0->GetYaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetYaxis()->SetNdivisions(414);    
   g0->Draw("AP");





TH1F *h1 = new TH1F("h1","", 100, 0.0, 3000) ;
TH1F *h2 = new TH1F("h2","", 100, 0.0, 3000) ;
TH1F *h3 = new TH1F("h3","", 100, 0.0, 3000) ;
TH1F *h4 = new TH1F("h4","", 100, 0.0, 3000) ;




   nlines = 0;

  in.open("mu-end-point-10GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 

//r = sqrt(xx*xx+yy*yy+zz*zz) ;
//teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

h1 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

//---------------------
   nlines = 0;

  in.open("mu-end-point-50GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 

//r = sqrt(xx*xx+yy*yy+zz*zz) ;
//teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

h2 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();
   //----------
      nlines = 0;

  in.open("mu-end-point-100GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 

//r = sqrt(xx*xx+yy*yy+zz*zz) ;
//teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

h3 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();


   //-------------------
       nlines = 0;

  in.open("mu-end-point-150GeV-opt4-5mm");

   while(1) {
 
  in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 

//r = sqrt(xx*xx+yy*yy+zz*zz) ;
//teta_Z = acos (pzz/sqrt(pxx*pxx+pyy*pyy+pzz*pzz)) ;

h4 -> Fill(zz);


   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();


/*
  // TGraph *g3 = new TGraph(n, mxi, omega3);   
//   TGraph *g1 = new TGraph(n, eneu, rtr2D);      

//   g1->SetMarkerStyle(28);
   g3->SetMarkerStyle(20);   
   g3->SetMarkerSize(0.7);      
//   g1->SetMarkerColor(kBlue);
//   g1->SetMarkerColor(kGreen);   
   g3->SetMarkerColor(kBlue);    
   legend->AddEntry(g3,"C^{12}");           
//   g1->SetMarkerColor(kBlue);         
//   legend->AddEntry(g1,"m_{#chi}(GeV)  -  #Omega h^{2}");
//   legend->AddEntry(g1,"Eneu-Track2D");   
   g3->Draw("P");
*/
//-----------------------------------

      

//   h1->SetFillColor(kGreen);
 h1->SetFillColor(kBlue-4);  
//    h1->SetLineColor(kCyan);
//h1->SetPointWidth(3);
 legend->AddEntry(h1,"10Gev");
   h1->Draw("sames");

 h2->SetFillColor(kGreen-2);  
//    h1->SetLineColor(kCyan);
//h1->SetPointWidth(3);
 legend->AddEntry(h2,"50Gev");
   h2->Draw("sames");

   h3->SetFillColor(kRed-3);  
//    h1->SetLineColor(kCyan);
//h1->SetPointWidth(3);
 legend->AddEntry(h3,"100Gev");
   h3->Draw("sames");

   h4->SetFillColor(kMagenta-2);  
//    h1->SetLineColor(kCyan);
//h1->SetPointWidth(3);
 legend->AddEntry(h4,"150Gev");
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
