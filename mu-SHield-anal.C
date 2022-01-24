TCanvas* graph()
{
//   gStyle->SetOptStat(0);
//   gStyle->SetOptFit();

//    TCanvas *c = new TCanvas("c","Track length shortlived particle",0,0,1000,1000);
//      TCanvas *c = new TCanvas("c"," H tracks Parameters  ",0,0,1200,1000); 
         TCanvas *c = new TCanvas("c"," cos  cos**2 primers ",0,0,1000,800);
//   c->Divide(2,1);
  Int_t nlines=0,nev,n=3,nlines1=0,nlines2=0,nlines3=0,nlines4=0,nlines5=0;
   Float_t e;
//   Double_t tr_len;
     Double_t alfa, pii=3.14159265;
 
TLegend *legend = new TLegend(.68,.58,.88,.76);

 
  Int_t i,nsob = 0, npart, np_=0, npi_=0, neta_=0, nmu_part; 
  Int_t ntr, npoint; 
   Double_t nn, f1,f2,fii;
  Double_t  mpart, px, py,pz,ee,eta_part,eta_part1,ptot22,ptrans;
 Double_t EDEP[7], Esumm, Emu_tot, mmu=0.10566;
  Int_t  Nedep[8];

Double_t aa1[10000],bb1[10000],dd1[10000];
Double_t aa2[10000],bb2[10000],dd2[10000];
Double_t aa3[10000],bb3[10000],dd3[10000];
Double_t aa4[10000],bb4[10000],dd4[10000];
Double_t aa5[10000],bb5[10000],dd5[10000];

//  Double_t x[2]={0,15.0},y[2]={0.0,10000.0};   

//  Double_t x[2]={0.0,1500.},y[2]={0.0,400.0};   
  Double_t x[2]={80.0,100.},y[2]={0.0,100.0}, z[2]={0.0,0.01};   
 
   ifstream in; 
   ofstream im;




//  ********************************************************************

//   c->cd(1);

   TGraph2D *g0 = new TGraph2D(2,x,y,z);

 g0->SetTitle("#mu,50 GeV"); 
       
       
 
   g0->GetXaxis()->SetTitle("#Delta(E_{#mu})%"); 
   g0->GetXaxis()->SetTitleOffset(1.5);
           
   g0->GetXaxis()->SetLabelSize(0.030);
//   g0->GetXaxis()->SetNdivisions(205);
   g0->GetXaxis()->SetNdivisions(414);   

 g0->GetYaxis()->SetTitle("Z, cm"); 
 g0->GetYaxis()->SetTitleOffset(1.5);     
   g0->GetYaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetYaxis()->SetNdivisions(414);    

g0->GetZaxis()->SetTitle("#Theta_{z}(CSca), rad");
g0->GetZaxis()->SetTitleOffset(1.5);        
   g0->GetZaxis()->SetLabelSize(0.030);
//   g0->GetYaxis()->SetNdivisions(205);
   g0->GetZaxis()->SetNdivisions(414);    

   g0->Draw("P");


		
	  in.open("mu-scattering-info-50GeV-opt4-0-1cm");
//       im.open("p-pi0-eta0_7-2_8-6");  

//        im.open("p-pi0-eta0_gt5");   
	im.open("out-file");  

printf("   *1*  \n");

  while(1) {
//printf("   *3*  \n"); 

  in >> Nedep[0]>> Nedep[1]>>Nedep[2]>>Nedep[3]>>Nedep[4]>>EDEP[0]>>EDEP[1]>>EDEP[2]>>EDEP[3]>>EDEP[4]>>EDEP[5]>>EDEP[6]>>Nedep[5]>> Nedep[6]>>Nedep[7];
  
//printf("   *4*  \n"); 
 
 Emu_tot=EDEP[3]+mmu;
Double_t dEmu= 100.* Emu_tot/(50.0+mmu);
Double_t pp=sqrt(EDEP[4]*EDEP[4]+ EDEP[5]*EDEP[5] +EDEP[6]*EDEP[6]);
Double_t tetaz=acos(EDEP[6]/pp);

//printf(" %d  %d  %d  %d  %d  %7.6e  %7.6e  %7.6e  %7.6e  %7.6e  %7.6e  %7.6e  %d  %d  %d  \n",Nedep[0],Nedep[1],Nedep[2],Nedep[3],Nedep[4],EDEP[0],EDEP[1],EDEP[2],
//EDEP[3],EDEP[4],EDEP[5],EDEP[6],Nedep[5],Nedep[6],Nedep[7]);

printf(" %7.6e  %7.6e  %7.6e\n",dEmu,EDEP[2],tetaz);
// im << "  nmu_part="<< nmu_part<<" EDEP[0]="<<EDEP[0]<<" EDEP[49]="<<EDEP[49]<<endl;

if(Nedep[2]< 98 && Nedep[3]==1 && Nedep[4]==888 ){ printf("   * 000 *  \n"); 
//nlines++;
//h1 -> SetPoint(nlines,dEmu,EDEP[2],tetaz);
 aa1[nlines] =  dEmu;
 bb1[nlines] =  EDEP[2];
 dd1[nlines] =  tetaz;
 nlines++;
                                 }


if(Nedep[2]< 98 && Nedep[3]==2 && Nedep[4]==888){ printf("   * 111 *  \n"); 
//nlines1++;
//h2 -> SetPoint(nlines1,dEmu,EDEP[2],tetaz);

 aa2[nlines1] =  dEmu;
 bb2[nlines1] =  EDEP[2];
 dd2[nlines1] =  tetaz;
 nlines1++;
   

                                 }


if(Nedep[2]< 98 && Nedep[3]>=3 && Nedep[4]==888){ printf("   * 222 *  \n"); 
//nlines2++;
//h3 -> SetPoint(nlines2,dEmu,EDEP[2],tetaz);

 aa3[nlines2] =  dEmu;
 bb3[nlines2] =  EDEP[2];
 dd3[nlines2] =  tetaz;
 nlines2++;
  
                                 }


if(Nedep[2] == 98 && Nedep[3]==0 && Nedep[4]==777){ printf("   * 333 *  \n"); 
//nlines3++;
//h4 -> SetPoint(nlines3,dEmu,EDEP[2],tetaz);
 aa4[nlines3] =  dEmu;
 bb4[nlines3] =  EDEP[2];
 dd4[nlines3] =  tetaz;
 nlines3++;
 
                                 }


if(Nedep[2] == 98 && Nedep[3]>0 && Nedep[4]==777){ printf("   * 444 *  \n"); 
//nlines4++;
//h5 -> SetPoint(nlines4,dEmu,EDEP[2],tetaz);

 aa5[nlines4] =  dEmu;
 bb5[nlines4] =  EDEP[2];
 dd5[nlines4] =  tetaz;
 nlines4++;
 

                                 }
   if (!in.good())  break;  
           }
	   
 printf(" Found %d  entries\n",nlines);

 
  np_=0; npi_=0 ;neta_=0;

 
   in.close();


TGraph2D  *h1 = new TGraph2D(nlines,aa1,bb1,dd1);

h1->SetMarkerStyle(20);   
h1->SetMarkerColor(kBlue);
h1->SetMarkerSize(0.8);  
legend->AddEntry(h1," Nscat=1");
h1->Draw("Psame");


TGraph2D  *h2 = new TGraph2D(nlines,aa2,bb2,dd2);
	
h2->SetMarkerStyle(20);   
h2->SetMarkerColor(kMagenta+3);
h2->SetMarkerSize(0.8);  
legend->AddEntry(h2," Nscat=2");
    h2->Draw("Psame");

TGraph2D  *h3 = new TGraph2D(nlines,aa3,bb3,dd3);

h3->SetMarkerStyle(20);   
h3->SetMarkerColor(kOrange+8);
h3->SetMarkerSize(0.8);  
legend->AddEntry(h3," Nscat>=3");
    h3->Draw("Psame");


TGraph2D  *h4 = new TGraph2D(nlines,aa4,bb4,dd4);

h4->SetMarkerStyle(20);   
h4->SetMarkerColor(kBlack);
h4->SetMarkerSize(0.5);  
legend->AddEntry(h4," Nscat=0, range=100cm");
    h4->Draw("Psame");


TGraph2D  *h5 = new TGraph2D(nlines,aa5,bb5,dd5);

h5->SetMarkerStyle(20);   
h5->SetMarkerColor(kGreen+1);
h5->SetMarkerSize(0.5);  
legend->AddEntry(h5," Nscat>0, range=100cm");


    h5->Draw("Psame");



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
