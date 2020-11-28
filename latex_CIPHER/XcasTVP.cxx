TVP(L,F,nom,nomv,ff,ftt,trigo,nmr):={

nl:=size(L);
fp:=[];
S:=[];
f:=[unapply(ff[0],t),unapply(ff[1],t)];
fp:=[function_diff(f[0]),function_diff(f[1])];
Z:=[];
LLL:=[];


all_trig_solutions:=1;
reset_solve_counter(-1,-1);

for(d:=0;d<=1;d++){
LLL:=concat(L,F[d]);
Z:=LLL union Z;
SS:=solve(factor(simplify(fp[d](t))),t);
ns:=size(SS);


for(k:=0;k<ns;k++){
if(trigo==t){
m:=0;
while(evalf(simplify(subst(SS[k],n_1=m)))<=evalf(L[nl-1])){

S:=concat(S,simplify(subst(SS[k],n_1=m)));m:=m+1;

};m:=-1;
while(evalf(subst(SS[k],n_1=m))>=L[0]){

S:=concat(S,simplify(subst(SS[k],n_1=m)));m:=m-1;

}
}else{
S:=concat(S,SS);
}
}


  si size(S)>0 alors   pour j de 0 jusque size(S)-1 faire
                             qq:=member(simplify(S[j]),Z)==0;
                             kk:=(evalf(S[j])>=evalf(L[0])) and (evalf(S[j])<=evalf(L[nl-1]));
                          if(kk==1){if(qq==1){Z:=append(Z,simplify(S[j]))}};
                          fpour
  fsi;
Z:=sort(Z);
nz:=size(Z);


 tantque evalf(Z[0])==evalf(Z[1]) faire Z:=Z[1..nz-1];nz:=size(Z);
     ftantque;




nz:=size(Z);
u:=1;
 tantque (u<nz-2) and (nz>2) faire
     tantque evalf(Z[u])==evalf(Z[u+1]) faire
         Z:=augment(Z[0..u-1],Z[u+1..nz-1]);nz:=size(Z);
     ftantque;
  u:=u+1;
 ftantque;


 };

Z:=sort(Z);
nz:=size(Z);



 l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:="",""; lf:="","";lsp:="","";
pour m de 0 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";fpour;

 lsi:="","";

FFF:=[[],[]];

for(d:=0;d<=1;d++){
FFF[d]:=concat(F[d],[-infinity,+infinity]);
       k0:= evalf(limit(f[d](x),x=Z[0],1))> evalf(limit(f[d](x),x=Z[1],-1));
       kz:=evalf(limit(f[d](x),x=Z[nz-1],-1))> evalf(limit(f[d](x),x=Z[nz-2],1));
//}
//$
 lsi[d]:=lsic+nom[d]+"'("+nomv+")}$ etex);"+if(member(Z[0],FFF[d])==0){"valBarre(btex $"+latex(simplify(fp[d](Z[0])))+"$ etex);"}else{if(Z[0]==-infinity){" "}else{"nonDefBarre;
"}}+
     if(Z[0]==-infinity){if(sign(evalf(fp[d](if(Z[1]==+infinity){0}else{Z[1]-10^(-5)})))==1){"plus;"}else{"moins;"}}else{if(member(Z[0],F[d])==0){
                                                    if(sign(fp[d](Z[0]+10^(-5)))==1){"plus;"}else{"moins;"}}else{
                                                         if(sign(fp[d]((Z[0]+10^(-5))))==1){"plus;"}else{"moins;"} }}

if(nz>2){ for(r:=1; r<=nz-2;r++){      ksp:=evalf(fp[d](Z[r]+0.01))>0;
                                               lsp[d]:=lsp[d]+if(member(Z[r],F[d])==0){"valBarre(btex $"+latex(simplify(fp[d](Z[r])))+"$ etex);"}else{"nonDefBarre;"}+
                                                if(ksp==1){"plus;"}else{"moins;"}
                                                  }; }

lsf[d]:=if(member(Z[nz-1],FFF[d])==0){"valBarre(btex $"+latex(simplify(fp[d](Z[nz-1])))+"$ etex);"}else{if(Z[nz-1]==+infinity){" "}else{"nonDefBarre;"}}




 }











 lm0:=1,2; li:=1,2; krm:=1,2; krp:=1,2; lmrm:=1,2; lmrp:=1,2; lp:="",""; lnz:=1,2; lf:=1,2; Kz:=1,2;K0:=1,2;


for(d:=0;d<=1;d++){
   K0[d]:= evalf(limit(f[d](x),x=Z[0],1))> evalf(limit(f[d](x),x=Z[1],-1));
  Kz[d]:=evalf(limit(f[d](x),x,Z[nz-1],-1))> evalf(limit(f[d](x),x,Z[nz-2],1));
//{
//$
lm0[d]:=limit(f[d](x),x,Z[0],1)==-infinity;
     li[d]:=lvic+nom[d]+"}$ etex);"+
           if(member(Z[0],F[d])==0){"valPos(btex $"+if(lm0[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x,Z[0],1)))}+"$ etex,"}
             else{"nonDefBarre;limDroite(btex $"+if(lm0[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x,Z[0],1)))}+"$ etex,"}+
           if(K0[d]==1){"1"}else{"0"}+
                         ");";

                     if(nz>2){ for(r:=1; r<=nz-2;r++){ krm[d]:=evalf(limit(f[d](x),x=Z[r-1],1))< evalf(limit(f[d](x),x=Z[r],-1));
                                                 krp[d]:=evalf(limit(f[d](x),x=Z[r],1))> evalf(limit(f[d](x),x,Z[r+1],-1)) ;
                         lmrm[d]:=limit(f[d](x),x,Z[r],-1)==-infinity;lmrp[d]:=limit(f[d](x),x,Z[r],1)==-infinity;
                                                  lp[d]:=lp[d]+if(member(Z[r],F[d])){
                                    "limGauche(btex
                                    $"+if(lmrm[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x,Z[r],-1)))}+"$
                                    etex,"+if(krm[d]==1){"1);"}else{"0);"}+"nonDefBarre;limDroite(btex $"+if(lmrp[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x,Z[r],1)))}+"$ etex,"+if(krp[d]==1){"1);"}else{"0);"}}
                                          else{"valPos(btex          $"+latex(simplify(f[d](Z[r])))+"$
                                            etex,"+if(sign(evalf(fp[d](Z[r]-0.001)))==sign(evalf((fp[d](Z[r]+0.001))) )){"0.5);"}else{if(krp[d]==1){"1);"}else{"0);
"}}}
                                                   }; }

lnz[d]:=limit(f[d](x),x=Z[nz-1],-1)==-infinity;


lf[d]:=if(member(Z[nz-1],F[d])==0){"valPos(btex $"+
           if(lnz[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x=Z[nz-1],-1)))}+"$ etex,"+
             if(Kz[d]==1){"1);"}else{"0);"}}
    else{"limGauche(btex $"+
         if(lnz[d]==1){"-\\infty"}else{latex(simplify(limit(f[d](x),x=Z[nz-1],-1)))}+"$ etex,"+
           if(Kz[d]==1){"1);nonDefBarre;"}else{"0);nonDefBarre;"}};






}








MetaLfc:=if(ftt==2){if(nz>2){"

beginTableau("+nmr+")"+
        l0+lsi[0]+lsp[0]+lsf[0]+lsi[1]+lsp[1]+lsf[1]+"
endTableau;

";}else{
"beginTableau("+nmr+")"+
        l0+
lsi[0]+lsf[0]+lsi[1]+lsf[1]+"
endTableau;

";
}
}else{ if(ftt==0){if(nz>2){"beginTableau("+nmr+")"+
        l0+
li[0]+
lp[0]+
lf[0]+
li[1]+
lp[1]+
lf[1]
+"
endTableau;

";}else{"beginTableau("+nmr+")"+
        l0+
li[0]+
lf[0]+
li[1]+
lf[1]
+"
endTableau;

";}}else{
if(nz>2){"beginTableau("+nmr+")"+
        l0+
lsi[0]+lsp[0]+lsf[0]+
li[0]+
lp[0]+
lf[0]+
lsi[1]+lsp[1]+lsf[1]+
li[1]+
lp[1]+
lf[1]
+"
endTableau;

";}else{"beginTableau("+nmr+")"+
        l0+
lsi[0]+lsf[0]+
li[0]+
lf[0]+
lsi[1]+lsf[1]+
li[1]+
lf[1]
+"
endTableau;

";}
}
}

sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);

}:;
