

TVapp(L,F,nom,nomv,f,ftt,nmr):={
local  nl,fp,z0,z,nz,S,k,j,m,kk,kok,Z,l0,lp,lf,lsp,k0,kz,lsi,r,ksp,lsf,lm0,li,krm,krp,lmrm,lmrp,lnz;

nl:=size(L);
f:=unapply(f,x);
fp:=function_diff(f);
z0:=concat(L,F);z:=sort(z0);
nz:=size(z);



S:=NULL;



if(L==[-infinity,+infinity]){j:=[seq(-50+2*k,k=0..50)]minus F;
  for k in j do for(m:=-5;m<=5;m++){S:=S,resoudre_numerique(fp(y),y,k+m*0.1,k+(m+1)*0.1,bisection_solver)};end_for}
else{if(L[0]==-infinity){j:=[seq(2*k,k=-25..0.5*floor(L[1]))] minus F;
  for k in j do for(m:=-5;m<=5;m++){ S:=S,resoudre_numerique(fp(y),y,k+m*0.1,k+(m+1)*0.1,bisection_solver)};end_for}
else{if(L[1]==+infinity){
j:=[seq(2*k,k=floor(0.5*L[0])..0.5*50)] minus F;
  for k in j do for(m:=-5;m<=5;m++){ S:=S,resoudre_numerique(fp(y),y,k+m*0.1,k+(m+1)*0.1,bisection_solver)};end_for
}
else{ j:=[seq(2*k,k=0.5*floor(z[0])..0.5*floor(z[nz-1]))] minus F;
  for k in j do  for(m:=-5;m<=5;m++){S:=S,resoudre_numerique(fp(y),y,k+m*0.1,k+(m+1)*0.1,bisection_solver)};end_for }
  }};




si size(S)>0 alors   pour j de 0 jusque size(S)-1 faire
                             kk:=(re(S[j])==S[j]);kok:=(evalf(S[j])>=L[0]) and (evalf(S[j])<=L[1]);
                          if(kk==1){if(kok==1){z:=append(z,simplify(S[j]))}};
                          fpour;
fsi;


S:=NULL;
S:=S,z[0];
for(j:=1;j<size(z);j++){
 if(z[j]!=undef and (abs(z[j])>1e-15 or z[j]==0)){
   S:=S,z[j]};
}
z:=[S];

Z:=sort(z);
nz:=size(Z);

S:=NULL;
S:=S,Z[0];
for(j:=1;j<nz;j++){
 if(Z[j]!=S[size(S)-1]){
   S:=S,Z[j]};
}
Z:=[S];


nz:=size(Z);
l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:=" "; lf:=" ";lsp:=" ";
pour m de 0 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";fpour;

       k0:= evalf(limit(f(x),x,Z[0],1))> evalf(limit(f(x),x,Z[1],-1));
       kz:=evalf(limit(f(x),x,Z[nz-1],-1))> evalf(limit(f(x),x,Z[nz-2],1));

lsi:=lsic+nom+"'("+nomv+")}$ etex);"+
     if(Z[0]==-infinity){if(sign(evalf(fp(if(Z[1]==+infinity){0}else{Z[1]-10^(-5)})))==1.0){"plus;"}else{"moins;"}}else{if(member(Z[0],F)==0){
                                                    if(fp(Z[0])==0){"valBarre(btex 0 etex);"}else{" "}+
                                                    if(evalf(sign(fp(Z[0]+10^(-5))))==1.0){"plus;"}else{"moins;"}}else{"nonDefBarre;"+
                                                         if(evalf(sign(fp((Z[0]+10^(-5)))))==1.0){"plus;"}else{"moins;"} }}

if(nz>2){ for(r:=1; r<=nz-2;r++){      ksp:=evalf(fp(Z[r]+0.01))>0;
                                               lsp:=lsp+if(member(Z[r],F)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}+
                                                if(ksp==1){"plus;"}else{"moins;"}
                                                  }; }

lsf:=if(member(Z[nz-1],F)==0){""}else{"nonDefBarre;
"}
lm0:=limit(f(x),x,Z[0],1)==-infinity;
     li:=lvic+nom+"}$ etex);"+
           if(member(Z[0],F)==0){"valPos(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}
             else{"nonDefBarre;limDroite(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}+
           if(k0==1){"1"}else{"0"}+
                         ");";

                     if(nz>2){ for(r:=1; r<=nz-2;r++){  krm:=evalf(limit(f(x),x,Z[r-1],1))< evalf(limit(f(x),x,Z[r],-1));
                                                 krp:=evalf(limit(f(x),x,Z[r],1))> evalf(limit(f(x),x,Z[r+1],-1)) ;
                         lmrm:=limit(f(x),x,Z[r],-1)==-infinity;lmrp:=limit(f(x),x,Z[r],1)==-infinity;
                                                  lp:=lp+if(member(Z[r],F)){
                                    "limGauche(btex $"+if(lmrm==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],-1)))}+"$ etex,"+if(krm==1){"1);"}else{"0);"}+"nonDefBarre;limDroite(btex $"+if(lmrp==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],1)))}+"$ etex,"+if(krp==1){"1);"}else{"0);"}}
                                          else{"valPos(btex          $"+latex(simplify(f(Z[r])))+"$
                                            etex,"+if(sign(evalf(fp(Z[r]-0.01)))==sign(fp(Z[r]+0.01))){"0.5);"}else{if(krp==1){"1);"}else{"0);
"}}}
                                                   }; }

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


 }:;







