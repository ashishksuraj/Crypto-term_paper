


TVIex(L,F,nom,nomv,f,ftt,ao,trigo,nmr):={
nl:=size(L);
f:=unapply(f,x);
fp:=function_diff(f);
Z:=concat(L,F);
S:=[];

Sex:=NULL;
Zex:=solve(f(x)=ao);
Zex:=sort(Zex);
for(j:=0;j<size(Zex);j++){
if((evalf(Zex[j])>=evalf(L[0])) and (evalf(Zex[j])<=evalf(L[nl-1]))){Sex:=Sex,Zex[j]};
};
Sex:=[Sex];








if(trigo==t){
all_trig_solutions:=1;
reset_solve_counter(-1,-1);
SS:=solve(factor(simplify(fp(x))),x);
ns:=size(SS);
for(k:=0;k<ns;k++){
m:=0;
while(evalf(simplify(subst(SS[k],n_1=m)))<=evalf(L[nl-1])){
S:=concat(S,simplify(subst(SS[k],n_1=m)));m:=m+1;
};m:=-1;
while(evalf(subst(SS[k],n_1=m))>=L[0]){
S:=concat(S,simplify(subst(SS[k],n_1=m)));m:=m-1;
}
}
}else{
S:=solve(factor(simplify(fp(x))),x);
}

  si size(S)>0 alors   pour j de 0 jusque size(S)-1 faire
                            kk:=(evalf(S[j])>=evalf(L[0])) and (evalf(S[j])<=evalf(L[nl-1]));
                          if(kk==1){Z:=append(Z,simplify(S[j]))};
                          fpour
  fsi;



 Z:=sort([op(set[op(Z)])]);


nz:=size(Z);
l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:=" "; lf:=" ";lsp:=" ";



LI:=limit(f(x),x,Z[0],1);
LF:=limit(f(x),x,Z[nz-1],-1);
LP:=NULL;
PB:=1;
if(nz>2){                                                       for(r:=1;
  r<=nz-2;r++){LP:=LP,if(member(Z[r],F)){limit(f(x),x,Z[r],-1),limit(f(x),x,Z[r],1)}else{f(Z[r])};
if(member(Z[r],F)){PB:=PB,0,1}else{PB:=PB,1};
}
};
if(nz>2){ LL:=[LI,LP,LF]; PB:=[PB,1]}else{LL:=[LI,LF];PB:=[1,1]};

NL:=size(LL);
A:=NULL;aa:=0;
kk:=0;



if(NL==nz){for(k:=0;k<nz-1;k++){TestS:=(evalf(sign(LL[k]-ao))==evalf(sign(LL[k+1]-ao))) or (evalf(sign(LL[k]-ao))==0.0)or (evalf(sign(LL[k+1]-ao))==0.0);
if(TestS==0){A:=A,aa;l0:=l0+"val(btex $"+latex(Z[k])+"$ etex);"+"val(btex $"+latex(simplify(Sex[aa]))+"$ etex);";aa:=aa+1;}else{l0:=l0+"val(btex $"+latex(Z[k])+"$ etex);"}}
l0:=l0+"val(btex $"+latex(Z[nz-1])+"$ etex);"};
//chgmt NL->nz
if(NL>nz){for(k:=0;k<NL-1;k++){TestS:=(evalf(sign(LL[k]-ao))==evalf(sign(LL[k+1]-ao))) or (evalf(sign(LL[k]-ao))==0.0)or (evalf(sign(LL[k+1]-ao))==0.0);

if(PB[k]==1){if(TestS==0){
   A:=A,aa;l0:=l0+"val(btex $"+latex(Z[kk])+"$ etex);"+"val(btex $"+latex(simplify(Sex[aa]))+"$ etex);";aa:=aa+1;kk:=kk+1}
else{l0:=l0+"val(btex $"+latex(Z[kk])+"$ etex);";kk:=kk+1}};
}

 l0:=l0+"val(btex $"+latex(Z[nz-1])+"$ etex);"

 };


TestS:=(evalf(sign(LL[0]-ao))==evalf(sign(LL[1]-ao))) or (evalf(sign(LL[0]-ao))==0.0) or (evalf(sign(LL[1]-ao))==0.0);
       k0:= evalf(limit(f(x),x,Z[0],1))> evalf(limit(f(x),x,Z[1],-1));
       kz:=evalf(limit(f(x),x,Z[nz-1],-1))> evalf(limit(f(x),x,Z[nz-2],1));

lsi:=lsic+nom+"'("+nomv+")}$ etex);"+
     if(Z[0]==-infinity){if(evalf(sign(fp(if(Z[1]==+infinity){0}else{Z[1]-10^(-5)})))==1){"plus;"}else{"moins;"}}else{if(member(Z[0],F)==0){
                                                    if(fp(Z[0])==0){"valBarre(btex 0 etex);"}else{" "}+
                                                    if(sign(fp((Z[0]+10^(-3))))==1){"plus;"}else{"moins;"}}else{"nonDefBarre;"+
                                                         if(sign(fp(10^(-3)+Z[0]))==1){"plus;"}else{"moins;"} }}+if(TestS==0){"valBarre(btex$
                                                       $ etex);"+
if(evalf(sign(fp(10^(-3)+ifte(Z[0]==-infinity,ifte(Z[1]==+infinity,ifte(member(0,F)==0,0,0.01),ifte(member(Z[1]-1,F)==0,Z[1]-1,Z[1]-1.1)),Z[0]))))==1.0){"plus;"}else{"moins;"}}else{" "};




if(nz>2){rr:=1; if(nz==NL){for(r:=1; r<=NL-2;r++){ TestS:=(evalf(sign(LL[r]-ao))==evalf(sign(LL[r+1]-ao))) or (evalf(sign(LL[r]-ao))==0.0)or (evalf(sign(LL[r+1]-ao))==0.0);
                                                 ksp:=evalf(fp(Z[r]+0.01))>0;
                                                 TestL:=(abs(LL[r])==abs(LL[r+1]));
                                 lsp:=lsp+if(member(Z[r],F)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}+
                                  if(ksp==1){"plus;"}else{"moins;"}+if(TestS==0){"valBarre(btex $  $ etex);"}else{" "}+if(TestS==0){if(ksp==1){"plus;"}else{"moins;"}}else{" "};
                                          }}
else{for(r:=1; r<=NL-2;r++){kspp:=evalf(fp(Z[rr]+0.01))>0;TestS:=(evalf(sign(LL[r]-ao))==evalf(sign(LL[r+1]-ao))) or (evalf(sign(LL[r]-ao))==0.0)or (evalf(sign(LL[r+1]-ao))==0.0);

                      if(PB[r]==1){if(TestS==0){lsp:=lsp+if(member(Z[rr],F)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}+
                                  if(kspp==1){"plus;"}else{"moins;"}+"valBarre(btex $  $ etex);"+if(kspp==1){"plus;"}else{"moins;"};rr:=rr+1;}
                                    else{lsp:=lsp+if(member(Z[rr],F)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}+
                                  if(kspp==1){"plus;"}else{"moins;"};rr:=rr+1;}
}}}};




 lsf:=if(member(Z[nz-1],F)==0){" "}else{"nonDefBarre;"}



lm0:=limit(f(x),x,Z[0],1)==-infinity;




TestS:=(evalf(sign(LL[0]-ao))==evalf(sign(LL[1]-ao))) or (evalf(sign(LL[0]-ao))==0.0) or (evalf(sign(LL[1]-ao))==0.0);

     li:=lvic+nom+"}$ etex);
"+  if(member(Z[0],F)==0){"valPos(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}
             else{"nonDefBarre;limDroite(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}+
           if(k0==1){"1);"}else{"0);"}+if(TestS==0){"valPos(btex $ "+ao+" $ etex,0.5);"}else{" "};


                     if(nz>2){if(nz==NL){for(r:=1; r<=nz-2;r++){TestS:=(evalf(sign(LL[r]-ao))==evalf(sign(LL[r+1]-ao))) or (evalf(sign(LL[r]-ao))==0.0)or (evalf(sign(LL[r+1]-ao))==0.0);
                                                 krm:=evalf(limit(f(x),x,Z[r-1],1))< evalf(limit(f(x),x,Z[r],-1));
                                                 krp:=evalf(limit(f(x),x,Z[r],1))> evalf(limit(f(x),x,Z[r+1],-1)) ;
                         lmrm:=limit(f(x),x,Z[r],-1)==-infinity;lmrp:=limit(f(x),x,Z[r],1)==-infinity;
                                                  lp:=lp+if(member(Z[r],F)) {
                                    "limGauche(btex $"+if(lmrm==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],-1)))}+"$ etex,"+if(krm==1){"1);"}else{"0);"}+"nonDefBarre;limDroite(btex $"+if(lmrp==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],1)))}+"$ etex,"+if(krp==1){"1);"}else{"0);"}}
                                          else{"valPos(btex          $"+latex(simplify(f(Z[r])))+"$
                                            etex,"+if(evalf(sign(fp(Z[r]-0.01)))==sign(fp(Z[r]+0.01))){"0.5);"}else{if(krp==1){"1);"}else{"0);"}}}+if(TestS==0){"valPos(btex
                                            $ "+ao+" $ etex,0.5);"
                                                           }else{" "};
};//for
}else{rr:=1;for(r:=1; r<=NL-2;r++){TestS:=(evalf(sign(LL[r]-ao))==evalf(sign(LL[r+1]-ao))) or (evalf(sign(LL[r]-ao))==0.0)or (evalf(sign(LL[r+1]-ao))==0.0);
                                                 krm:=evalf(limit(f(x),x,Z[rr-1],1))< evalf(limit(f(x),x,Z[rr],-1));
                                                 krp:=evalf(limit(f(x),x,Z[rr],1))> evalf(limit(f(x),x,Z[rr+1],-1)) ;
                         lmrm:=limit(f(x),x,Z[rr],-1)==-infinity;lmrp:=limit(f(x),x,Z[rr],1)==-infinity; TestL:=(abs(LL[r])==abs(LL[r+1]));

if(PB[r]==1){if(TestS==0){lp:=lp+if(member(Z[rr],F)){
                                    "limGauche(btex $"+if(lmrm==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[rr],-1)))}+"$ etex,"+if(krm==1){"1);"}else{"0);"}+"nonDefBarre;limDroite(btex $"+if(lmrp==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[rr],1)))}+"$ etex,"+if(krp==1){"1);"}else{"0);"}}
                                          else{"valPos(btex          $"+latex(simplify(f(Z[rr])))+"$
                                            etex,"+if(evalf(sign(fp(Z[rr]-0.01)))==sign(fp(Z[rr]+0.01))){"0.5);"}else{if(krp==1){"1);"}else{"0);"}}}+"valPos(btex
                                            $ "+ao+" $ etex,0.5);
                                                                 ";rr:=rr+1;
}//  testS==0
else{lp:=lp+if(member(Z[rr],F)){
                                    "limGauche(btex $"+if(lmrm==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[rr],-1)))}+"$ etex,"+if(krm==1){"1);"}else{"0);"}+"nonDefBarre;limDroite(btex $"+if(lmrp==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[rr],1)))}+"$ etex,"+if(krp==1){"1);"}else{"0);"}}
                                          else{"valPos(btex          $"+latex(simplify(f(Z[rr])))+"$
                                            etex,"+if(evalf(sign(fp(Z[rr]-0.01)))==sign(fp(Z[rr]+0.01))){"0.5);"}else{if(krp==1){"1);"}else{"0);
                                                            "}}};rr:=rr+1;
}//else testS==0
}//PB[r]==1
}//for nz<NL
}// else nz<NL
//if nz=NL
};//if nz>2



lnz:=limit(f(x),x,Z[nz-1],-1)==-infinity;


lf:=if(member(Z[nz-1],F)==0){"valPos(btex $"+
           if(lnz==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[nz-1],-1)))}+"$ etex,"+
             if(kz==1){"1);"}else{"0);"}}
    else{"limGauche(btex $"+
         if(lnz==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[nz-1],-1)))}+"$ etex,"+
           if(kz==1){"1);nonDefBarre;"}else{"0);nonDefBarre;"}};







MetaLfc:= if(ftt==2){if(nz>2){"beginTableau("+nmr+")"+
        l0+lsi+lsp+lsf+"
endTableau;

";}else{
"beginTableau("+nmr+")"+
        l0+
lsi+lsf+"
endTableau;

";
}
}else{
if(ftt==0){if(nz>2){"beginTableau("+nmr+")"+
        l0+
li+
lp+
lf
+"
endTableau;

";}else{"beginTableau("+nmr+")"+
        l0+
li+
lf
+"
endTableau;
";}}else{
if(nz>2){"beginTableau("+nmr+")"+
        l0+
lsi+lsp+lsf+
li+
lp+
lf
+"
endTableau;

";}else{"beginTableau("+nmr+")"+
        l0+
lsi+lsf+
li+
lf
+"
endTableau;

";}
}};






sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);


 }:;


