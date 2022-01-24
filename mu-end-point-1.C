void histpalettecolor();
TCanvas* graph()
{
   TCanvas *C = new TCanvas("c"," Track length ",0,0,3000,60);
 
   gStyle->SetOptTitle(kFALSE);
   gStyle->SetOptStat(0);

   Int_t nlines = 0,  nev;
    Double_t Nev, pant, xx, yy, zz, Ekin, pxx, pyy, pzz, PPHC, tr, mpid, Nlev; 

    Double_t teta_Z,r;
 
      ifstream in;

   TH1F *h1 = new TH1F ("h1","Histogram drawn with full circles",100,0.0,3000);
   TH1F *h2 = new TH1F ("h2","Histogram drawn with full squares",100,0.0,3000);
   TH1F *h3 = new TH1F ("h3","Histogram drawn with full triangles up",100,0.0,3000);
   TH1F *h4 = new TH1F ("h4","Histogram drawn with full triangles down",100,0.0,3000);
  // TH1F *h5 = new TH1F ("h5","Histogram drawn with empty circles",100,-4,4);
 
  
   
   
   //-----------------
   
  nlines = 0;

  in.open("mu-end-point-10GeV-opt4-5mm");

   while(1)
   {
      in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 
     

   h1 -> Fill(zz);
   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();
 //------------------  

  nlines = 0;

  in.open("mu-end-point-50GeV-opt4-5mm");

   while(1)
   {
      in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 
     

   h2 -> Fill(zz);
   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

   //-------------
    nlines = 0;

  in.open("mu-end-point-100GeV-opt4-5mm");

   while(1)
   {
      in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 
     

   h3 -> Fill(zz);
   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

   //--------------

    nlines = 0;

  in.open("mu-end-point-150GeV-opt4-5mm");

   while(1)
   {
      in >> Nev >> pant >> xx >> yy >> zz >> Ekin >> pxx >> pyy >> pzz >> PPHC >> tr >> mpid; 
     

   h4 -> Fill(zz);
   if (!in.good())  break;  
    nlines++;
    

                   
           }	   
 printf(" Found %d  entries\n",nlines);
   in.close();

 
   h1->SetMarkerStyle(kFullCircle);
   h2->SetMarkerStyle(kFullSquare);
   h3->SetMarkerStyle(kFullTriangleUp);
   h4->SetMarkerStyle(kFullTriangleDown);
  // h5->SetMarkerStyle(kOpenCircle);
 
   h1->Draw("PLC PMC");
   h2->Draw("SAME PLC PMC");
   h3->Draw("SAME PLC PMC");
   h4->Draw("SAME PLC PMC");
  // h5->Draw("SAME PLC PMC");
 
   gPad->BuildLegend();
return C;
  }
