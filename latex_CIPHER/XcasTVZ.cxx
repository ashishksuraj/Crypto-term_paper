

TVZ(L,F,FF,nom,nomv,f,ftt,trigo,nmr):={
nl:=size(L);
nf:=size(FF);
 Ff:=NULL;IMIN:=NULL;IMAX:=NULL;
for(k:=0;k<nf;k++){
if(FF[k][0]>L[0]){Imin[k]:=FF[k][0];LL:=L}else{Imin[k]:=L[0];LL:=[L[1]]};
if(FF[k][1]<L[1]){Imax[k]:=FF[k][1];LL:=L}else{Imax[k]:=L[1];LL:=[L[0]]};
 Ff:=Ff,[Imin[k],Imax[k]];
 IMIN:=IMIN,Imin[k];
 IMAX:=IMAX,Imax[k];
 }
 FF:=[Ff];
 IMIN:=[IMIN];
 IMAX:=[IMAX];
 f:=unapply(f,x);
fp:=function_diff(f);
Z:=concat(LL,F);

for(k:=0;k<nf;k++){
Z:=concat(Z,FF[k]);
}

S:=[];


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
                         for(k:=0;k<nf;k++){
                           kk:=(evalf(S[j])>=evalf(L[0])) and (evalf(S[j])<=evalf(L[nl-1]));
                             kK:=(evalf(S[j])<evalf(Imin[k])) or (evalf(S[j])>evalf(Imax[k]));
                             Kk:=(kk) and kK;
                          if(Kk==1){Z:=append(Z,simplify(S[j]))};
                          }
                        fpour
  fsi;


Z:=sort([op(set[op(Z)])]);

nz:=size(Z);

for(j:=0;j<nf;j++){
 for(k:=1;k<nz;k++){
   if ((Z[k]>Imin[j])and(Z[k]<Imax[j])){Z:=augment(Z[0..k-1],Z[k+1..nz-1]);nz:=nz-1;
   }
  }
}
nz:=size(Z);

l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:=" "; lf:=" ";lsp:=" ";
pour m de 0 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";fpour;

       k0:= evalf(limit(f(x),x,Z[0],1))> evalf(limit(f(x),x,Z[1],-1));
       kz:=evalf(limit(f(x),x,Z[nz-1],-1))> evalf(limit(f(x),x,Z[nz-2],1));

lsi:=lsic+nom+"'("+nomv+")}$ etex);"+
if(member(Z[0],IMIN)!=0){if((member(Z[0],F)==0) and (fp(Z[0])!=undef)){"debutNonDef;"}else{"debutNonDefStrict;"}}else{if(Z[0]==-infinity){if(sign(evalf(fp(if(Z[1]==+infinity){0}else{Z[1]-10^(-5)})))==1.0){"plus;"}else{"moins;"}}else{if(member(Z[0],F)==0){
                                                    if(fp(Z[0])==0){"valBarre(btex 0 etex);"}else{" "}+
                                                    if(evalf(sign(fp(Z[0]+10^(-5))))==1.0){"plus;"}else{"moins;"}}else{"nonDefBarre;"+
                                                         if(evalf(sign(fp((Z[0]+10^(-5)))))==1.0){"plus;"}else{"moins;"} }}}



// modif 3 avril 2010

if(nz>2){ for(r:=1; r<=nz-2;r++){
             lsp:=lsp+
              if(member(Z[r],IMIN)!=0){
                if((member(Z[r],F)==0) and (fp(Z[r])!=undef)){"debutNonDef;"}
                else{"debutNonDefStrict;"}}
              else{if(member(Z[r],IMAX)!=0){if((member(Z[r],F)==0) and (fp(Z[r])!=undef)){"finNonDef;"}
                                                else{"finNonDefStrict;"}+
                                                if(evalf(fp(Z[r]+0.01))>0){"plus;"}
                                                else{"moins;"}}
                    else{if(member(Z[r],F)==0){"valBarre(btex 0 etex);"}
                          else{"nonDefBarre;"}+
                          if(evalf(fp(Z[r]+0.01))>0){"plus;"}
                          else{"moins;"}
                                                  }}
                            }};

// fin modif





lsf:=if(member(Z[nz-1],IMAX)!=0){if((member(Z[nz-1],F)==0) and (fp(Z[nz-1])!=undef)){"finNonDef;"}else{"finNonDefStrict;"}}else{if(member(Z[nz-1],F)==0){""}else{"nonDefBarre;
"}}


lm0:=limit(f(x),x,Z[0],1)==-infinity;
     li:=lvic  +nom+"}$ etex);"+
           if(member(Z[0],F)==0){"valPos(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}
             else{"nonDefBarre;limDroite(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}+
           if(k0==1){"1"}else{"0"}+
                         ");";

if(nz>2){
   for(r:=1; r<=nz-2;r++){
     krm:=evalf(limit(f(x),x,Z[r-1],1))< evalf(limit(f(x),x,Z[r],-1));
     krp:=evalf(limit(f(x),x,Z[r],1))> evalf(limit(f(x),x,Z[r+1],-1)) ;
     lmrm:=limit(f(x),x,Z[r],-1)==-infinity;lmrp:=limit(f(x),x,Z[r],1)==-infinity;

     lp:=lp+if(member(Z[r],IMIN)!=0){"limGauche(btex $"+if(lmrm==1){
             "-\\infty"}else{
                latex(simplify(limit(f(x),x,Z[r],-1)))}
         +"$ etex,"+if(krm==1){
             "1);"}else{"0);"}
         +if(member(Z[r],F)==0){"debutNonDef;"}else{"debutNonDefStrict;"}
       }//fsi Zr=Imin
      else{
        if (member(Z[r],IMAX)!=0){if(member(Z[r],F)==0){"finNonDef;"}else{"finNonDefStrict;"}+"limDroite(btex $"+if(lmrp==1){
             "-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],1)))}
         +"$ etex,"+if(krp==1){
             "1);"}else{"0);"}
       }else{
          if(member(Z[r],F)){
         "limGauche(btex $"+if(lmrm==1){
             "-\\infty"}else{
                latex(simplify(limit(f(x),x,Z[r],-1)))}
         +"$ etex,"+if(krm==1){
             "1);"}else{"0);"}
         +"nonDefBarre;limDroite(btex $"+if(lmrp==1){
             "-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],1)))}
         +"$ etex,"+if(krp==1){
             "1);"}else{"0);"}
         }//fsi (member Zr F)
          else{"valPos(btex$"+latex(simplify(f(Z[r])))+"$etex,"+
             if(sign(evalf(fp(Z[r]-0.01)))==sign(fp(Z[r]+0.01))){
               "0.5);"}else{
                    if(krp==1){
                       "1);"}else{"0);"}//felse(krp)
                    }//felse(valpos)
               }//felse(member Zr F)
               } //felse(Zr=Imax)
              }//felse(Zr=Imin)
           };//ffor
         }//fsi nz

lnz:=limit(f(x),x,Z[nz-1],-1)==-infinity;



lf:=if(member(Z[nz-1],F)==0){"valPos(btex $"+
           if(lnz==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[nz-1],-1)))}+"$ etex,"+
             if(kz==1){"1);"}else{"0);"}}
    else{"limGauche(btex $"+
         if(lnz==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[nz-1],-1)))}+"$ etex,"+
           if(kz==1){"1);nonDefBarre;"}else{"0);nonDefBarre;"}};





MetaLfc:=if(ftt==2){if(nz>2){"

beginTableau("+nmr+")"+
        l0+lsi+lsp+lsf+"
endTableau;

";}else{
"beginTableau("+nmr+")"+
        l0+
lsi+lsf+"
endTableau;

";
}
}else{ if(ftt==0){if(nz>2){"beginTableau("+nmr+")"+
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
}}


sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);

 }
:;


