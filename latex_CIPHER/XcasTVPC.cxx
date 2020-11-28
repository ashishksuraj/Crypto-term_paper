TVPC(L,F,FP,nom,nomv,f,ftt,trigo,nmr):={
nl:=size(L);
f:=unapply(f,x);
fp:=function_diff(f);
Z:=concat(L,F);
Z:=concat(Z,FP);
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
                             qq:=member(simplify(S[j]),Z)==0;
                             kk:=(evalf(S[j])>=evalf(L[0])) and (evalf(S[j])<=evalf(L[nl-1]));
                          if(kk==1){if(qq==1){Z:=append(Z,simplify(S[j]))}};
                          fpour
  fsi;
Z:=sort(Z);
nz:=size(Z);


 tantque evalf(Z[0])==evalf(Z[1]) faire Z:=Z[1..nz-1];nz:=size(Z);
     ftantque;







  si size(S)>0 alors   pour j de 0 jusque size(S)-1 faire
                             kk:=(evalf(S[j])>=evalf(L[0])) and (evalf(S[j])<=evalf(L[nl-1]));
                          if(kk==1){Z:=append(Z,simplify(S[j]))};
                          fpour
  fsi;


Z:=sort([op(set[op(Z)])]);

nz:=size(Z);
l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:=" "; lf:=" ";lsp:=" ";
pour m de 0 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";fpour;

       k0:= evalf(limit(f(x),x,Z[0],1))> evalf(limit(f(x),x,Z[1],-1));
       kz:=evalf(limit(f(x),x,Z[nz-1],-1))> evalf(limit(f(x),x,Z[nz-2],1));

lsi:=lsic+nom+"'("+nomv+")}$ etex);"+
     if(Z[0]==-infinity){if(sign(evalf(fp(if(Z[1]==+infinity){0}else{Z[1]-10^(-5)})))==1.0){"plus;"}else{"moins;"}}else{if(member(Z[0],FP)==0){
                                                    if(fp(Z[0])==0){"valBarre(btex 0 etex);"}else{" "}+
                                                    if(evalf(sign(fp(Z[0]+10^(-5))))==1.0){"plus;"}else{"moins;"}}else{"nonDefBarre;"+
                                                         if(evalf(sign(fp((Z[0]+10^(-5)))))==1.0){"plus;"}else{"moins;"} }}

if(nz>2){ for(r:=1; r<=nz-2;r++){      ksp:=evalf(fp(Z[r]+0.1))>0;
                                               lsp:=lsp+if(member(Z[r],FP)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}+
                                                if(ksp==1){"plus;"}else{"moins;"}
                                                  }; }

lsf:=if(member(Z[nz-1],FP)==0){""}else{"nonDefBarre;
"}
lm0:=limit(f(x),x,Z[0],1)==-infinity;
     li:=lvic+nom+"}$ etex);"+
           if(member(Z[0],F)==0){"valPos(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}
             else{"limDroite(btex $"+if(lm0==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[0],1)))}+"$ etex,"}+
           if(k0==1){"1"}else{"0"}+
                         ");";

                     if(nz>2){ for(r:=1; r<=nz-2;r++){ krm:=evalf(limit(f(x),x,Z[r-1],1))< evalf(limit(f(x),x,Z[r],-1));
                                                 krp:=evalf(limit(f(x),x,Z[r],1))> evalf(limit(f(x),x,Z[r+1],-1)) ;
                         lmrm:=limit(f(x),x,Z[r],-1)==-infinity;lmrp:=limit(f(x),x,Z[r],1)==-infinity;
                                                  lp:=lp+if(member(Z[r],F)){
                                    "valPos(btex
                                    $"+if(lmrm==1){"-\\infty"}else{latex(simplify(limit(f(x),x,Z[r],-1)))}+"$
                                    etex,"+if(krm==1){"1);"}else{"0);"} }
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
           if(kz==1){"1);"}else{"0);"}};





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

