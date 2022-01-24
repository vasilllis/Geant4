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
  Int_t ntr, npoint; 
   Double_t nn, f1,f2,fii;
  Double_t  mpart, px, py,pz,ee,eta_part,eta_part1,ptot22,ptrans;
 Double_t EDEP[50], Esumm, nle;


 
//  Double_t x[2]={0,15.0},y[2]={0.0,10000.0};   

 Double_t x[2]={0.0,150000.0},y[2]={0.0,2000.0};   
 // Double_t x[2]={5.0,20.},y[2]={0.0,600.0};   
 
   ifstream in; 
    ifstream in1;
  // ofstream im;
  // ofstream im2;



//  ********************************************************************

//   c->cd(1);

   TGraph*g0 = new TGraph(2,x,y);

 g0->SetTitle("Fe (10cm). Total energy deposit, MeV"); 
       
       
 
   g0->GetXaxis()->SetTitle("EnDep, MeV");         


   g0->GetXaxis()->SetLabelSize(0.030);
//   g0->GetXaxis()->SetNdivisions(205);
   g0->GetXaxis()->SetNdivisions(414);   
   g0->GetYaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetYaxis()->SetNdivisions(414);    
   g0->Draw("AP");


		
	  //in.open("10GeV-optWVI-mu-Endep_levels");


    TH1F *h1 = new TH1F("#mu, 10 GeV"," ",100, 0.0, 150000.0);
     TH1F *h2 = new TH1F("#mu, 50 GeV"," ",100, 0.0, 150000.0);
      TH1F *h3 = new TH1F("#mu, 100 GeV"," ",100, 0.0, 15000.0);
      TH1F *h4 = new TH1F("#mu, 100 GeV"," ",100, 0.0, 150000.0);
                                      
//TH1F *h1 = new TH1F("Pl5,#mu,150 GeV"," ",150, 0.0, 1500.0);
//TH1F *h2 = new TH1F("Pl10,#mu,150 GeV"," ",150, 0.0, 1500.0);
//TH1F *h3 = new TH1F("Pl20,#mu,150 GeV"," ",150, 0.0, 1500.0);
//TH1F *h4 = new TH1F("Pl30,#mu,150 GeV"," ",150, 0.0, 1500.0);
//TH1F *h5 = new TH1F("Pl40,#mu,150 GeV"," ",150, 0.0, 1500.0);
//TH1F *h6 = new TH1F("Pl50,#mu,150 GeV"," ",150, 0.0, 1500.0);

//TH1F *h1 = new TH1F("Pl5,#mu,150 GeV"," ",100, 5.0, 20.0);
//TH1F *h2 = new TH1F("Pl10,#mu,150 GeV"," ",100, 5.0, 20.0);
//TH1F *h3 = new TH1F("Pl20,#mu,150 GeV"," ",100, 5.0, 20.0);
//TH1F *h4 = new TH1F("Pl30,#mu,150 GeV"," ",100, 5.0, 20.0);
//TH1F *h5 = new TH1F("Pl40,#mu,150 GeV"," ",100, 5.0, 20.0);
//TH1F *h6 = new TH1F("Pl50,#mu,150 GeV"," ",100, 5.0, 20.0);



   nlines = 0;
   in.open("mu-Endep-levels-10GeV-opt4-5mm");
   while(1) {
 
  in >> nmu_part>>EDEP[0]>>EDEP[1]>>EDEP[2]>>EDEP[3]>>EDEP[4]>>EDEP[5]>>EDEP[6]>>EDEP[7]>>EDEP[8]>>EDEP[9] 
  >>EDEP[10]>>EDEP[11]>>EDEP[12]>>EDEP[13]>>EDEP[14]>>EDEP[15]>>EDEP[16]>>EDEP[17]>>EDEP[18]>>EDEP[19] 
  >>EDEP[20]>>EDEP[21]>>EDEP[22]>>EDEP[23]>>EDEP[24]>>EDEP[25]>>EDEP[26]>>EDEP[27]>>EDEP[28]>>EDEP[29]
  >>EDEP[30]>>EDEP[31]>>EDEP[32]>>EDEP[33]>>EDEP[34]>>EDEP[35]>>EDEP[36]>>EDEP[37]>>EDEP[38]>>EDEP[39]
 >>EDEP[40]>>EDEP[41]>>EDEP[42]>>EDEP[43]>>EDEP[44]>>EDEP[45]>>EDEP[46]>>EDEP[47]>>EDEP[48]>>EDEP[49] ;
 
// im << "  nmu_part="<< nmu_part<<" EDEP[0]="<<EDEP[0]<<" EDEP[49]="<<EDEP[49]<<endl;
 
   if (!in.good())  break;  


//  if(mpart== -888) im << npart <<mpart <<px <<py <<pz <<ee <<eta_part <<ptrans << endl;
//if (eta_part>=7.2 && eta_part<=8.6) im << npart<<"   "<<mpart<<"   " <<px<<"   " <<py<<"   " <<pz<<"   " <<ee<<"   " <<eta_part<<"   "<<ptrans<< endl;
//if (eta_part>=5.0) im << npart<<"   "<<mpart<<"   " <<px<<"   " <<py<<"   " <<pz<<"   " <<ee<<"   " <<eta_part<<"   "<<ptrans<< endl;

Esumm=0.0;

for (i=0; i<=49; i++){  Esumm+=EDEP[i];   }
cout << " Esumm ="<< Esumm<<endl;
h1->Fill(Esumm); 


//h1->Fill(EDEP[4]); 
//h2->Fill(EDEP[9]); 
//h3->Fill(EDEP[19]); 
//h4->Fill(EDEP[29]); 
//h5->Fill(EDEP[39]); 
//h6->Fill(EDEP[49]);

       nlines++;
                   
           }
	   
 printf(" Found %d  entries\n",nlines);

 
  np_=0; npi_=0 ;neta_=0;

 
   in.close();


//------------------
   nlines = 0;
   in.open("mu-Endep-levels-50GeV-opt4-5mm");
   while(1) {
    in >> nmu_part>>EDEP[0]>>EDEP[1]>>EDEP[2]>>EDEP[3]>>EDEP[4]>>EDEP[5]>>EDEP[6]>>EDEP[7]>>EDEP[8]>>EDEP[9] 
  >>EDEP[10]>>EDEP[11]>>EDEP[12]>>EDEP[13]>>EDEP[14]>>EDEP[15]>>EDEP[16]>>EDEP[17]>>EDEP[18]>>EDEP[19] 
  >>EDEP[20]>>EDEP[21]>>EDEP[22]>>EDEP[23]>>EDEP[24]>>EDEP[25]>>EDEP[26]>>EDEP[27]>>EDEP[28]>>EDEP[29]
  >>EDEP[30]>>EDEP[31]>>EDEP[32]>>EDEP[33]>>EDEP[34]>>EDEP[35]>>EDEP[36]>>EDEP[37]>>EDEP[38]>>EDEP[39]
 >>EDEP[40]>>EDEP[41]>>EDEP[42]>>EDEP[43]>>EDEP[44]>>EDEP[45]>>EDEP[46]>>EDEP[47]>>EDEP[48]>>EDEP[49] ;
 

 
   if (!in.good())  break;  
   Esumm=0.0;

for (i=0; i<=49; i++){  Esumm+=EDEP[i];   }
cout << " Esumm ="<< Esumm<<endl;
h2->Fill(Esumm); 
 nlines++;
                   
           }   
 printf(" Found %d  entries\n",nlines);

  np_=0; npi_=0 ;neta_=0;

   in.close();
//-------------------
 nlines = 0;
   in.open("mu-Endep-levels-100GeV-opt4-5mm");
   while(1) {
    in >> nmu_part>>EDEP[0]>>EDEP[1]>>EDEP[2]>>EDEP[3]>>EDEP[4]>>EDEP[5]>>EDEP[6]>>EDEP[7]>>EDEP[8]>>EDEP[9] 
  >>EDEP[10]>>EDEP[11]>>EDEP[12]>>EDEP[13]>>EDEP[14]>>EDEP[15]>>EDEP[16]>>EDEP[17]>>EDEP[18]>>EDEP[19] 
  >>EDEP[20]>>EDEP[21]>>EDEP[22]>>EDEP[23]>>EDEP[24]>>EDEP[25]>>EDEP[26]>>EDEP[27]>>EDEP[28]>>EDEP[29]
  >>EDEP[30]>>EDEP[31]>>EDEP[32]>>EDEP[33]>>EDEP[34]>>EDEP[35]>>EDEP[36]>>EDEP[37]>>EDEP[38]>>EDEP[39]
 >>EDEP[40]>>EDEP[41]>>EDEP[42]>>EDEP[43]>>EDEP[44]>>EDEP[45]>>EDEP[46]>>EDEP[47]>>EDEP[48]>>EDEP[49] ;
 

 
   if (!in.good())  break;  
   Esumm=0.0;

for (i=0; i<=49; i++){  Esumm+=EDEP[i];   }
cout << " Esumm ="<< Esumm<<endl;
h3->Fill(Esumm); 
 nlines++;
                   
           }   
 printf(" Found %d  entries\n",nlines);

  np_=0; npi_=0 ;neta_=0;

   in.close();

   //---------------
   nlines = 0;
   in.open("mu-Endep-levels-150GeV-opt4-5mm");
   while(1) {
    in >> nmu_part>>EDEP[0]>>EDEP[1]>>EDEP[2]>>EDEP[3]>>EDEP[4]>>EDEP[5]>>EDEP[6]>>EDEP[7]>>EDEP[8]>>EDEP[9] 
  >>EDEP[10]>>EDEP[11]>>EDEP[12]>>EDEP[13]>>EDEP[14]>>EDEP[15]>>EDEP[16]>>EDEP[17]>>EDEP[18]>>EDEP[19] 
  >>EDEP[20]>>EDEP[21]>>EDEP[22]>>EDEP[23]>>EDEP[24]>>EDEP[25]>>EDEP[26]>>EDEP[27]>>EDEP[28]>>EDEP[29]
  >>EDEP[30]>>EDEP[31]>>EDEP[32]>>EDEP[33]>>EDEP[34]>>EDEP[35]>>EDEP[36]>>EDEP[37]>>EDEP[38]>>EDEP[39]
 >>EDEP[40]>>EDEP[41]>>EDEP[42]>>EDEP[43]>>EDEP[44]>>EDEP[45]>>EDEP[46]>>EDEP[47]>>EDEP[48]>>EDEP[49] ;
 

 
   if (!in.good())  break;  
   Esumm=0.0;

for (i=0; i<=49; i++){  Esumm+=EDEP[i];   }
cout << " Esumm ="<< Esumm<<endl;
h4->Fill(Esumm); 
 nlines++;
                   
           }   
 printf(" Found %d  entries\n",nlines);

  np_=0; npi_=0 ;neta_=0;

   in.close();
 

      

//   h1->SetFillColor(kGreen);
 h1->SetLineColor(kBlue+4);  
//    h1->SetLineColor(kCyan);
h1->SetLineWidth(3);
 legend->AddEntry(h1,"10 GeV");
   h1->Draw("sames");

   printf(" ***** h1 drawn\n");

   h2->SetLineColor(kBlue);  
//    h1->SetLineColor(kCyan);
h2->SetLineWidth(3);
 legend->AddEntry(h2,"50 GeV");
   h2->Draw("sames");

   printf(" ***** h2 drawn\n"); 

 h3->SetLineColor(kBlue+8);  
//    h1->SetLineColor(kCyan);
h3->SetLineWidth(3);
 legend->AddEntry(h3,"100 GeV");
   h3->Draw("sames");

   printf(" ***** h3 drawn\n");


 h4->SetLineColor(kBlue+8);  
//    h1->SetLineColor(kCyan);
h4->SetLineWidth(3);
 legend->AddEntry(h4,"150 GeV");
   h4->Draw("sames");

   printf(" ***** h4 drawn\n");

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
// h2->SetLineColor(kBlue);  
//    h1->SetLineColor(kCyan);
 //legend->AddEntry(h2,"Pl10, EnDep");
 //  h2->Draw("sames");

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
 //h3->SetLineColor(kCyan+2);  
 //h3->SetLineColor(kBlue+4); 
//    h1->SetLineColor(kCyan);
 //h3->SetLineWidth(3);
 //legend->AddEntry(h3,"Pl20, EnDep");
  // h3->Draw("sames");

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
 //h4->SetLineColor(kGreen+3);  
// h4->SetLineColor(kBlue+4); 
//    h1->SetLineColor(kCyan);
 //h4->SetLineWidth(3);
// legend->AddEntry(h4,"Pl30, EnDep");
  // h4->Draw("sames");

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
 //h5->SetLineColor(kGreen); 
 // h5->SetLineColor(kBlue+4); 
//    h1->SetLineColor(kCyan);
 //h5->SetLineWidth(3);
 //legend->AddEntry(h5,"Pl40, EnDep");
 //  h5->Draw("sames");


//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

//   h1->SetFillColor(kGreen);
// h6->SetLineColor(kOrange);  
//h6->SetLineColor(kBlack);
//h6->SetLineColor(kBlue+4); 
//    h1->SetLineColor(kCyan);
 //h6->SetLineWidth(3);
 //legend->AddEntry(h6,"Pl50, EnDep");
 //  h6->Draw("sames");



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
