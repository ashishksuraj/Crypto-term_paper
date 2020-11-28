TSq(nomf,L,Fo,D,trigo,nmr):={
L:=apply(f->unapply(f,x),L);
Fo:=apply(f->unapply(f,x),Fo);
L:=concat(L,Fo);
n:=size(L);
Z:=NULL;
m:=size(Fo);
F:=NULL;FF:=NULL;
mini:=D[0]; maxi:=D[1];
S:=[];
SF:=[];

pour k de 0 jusque n-1 faire



if(trigo==t){
all_trig_solutions:=1;
reset_solve_counter(-1,-1);
SS:=solve(factor(simplify(L[k](x))),x);
ns:=size(SS);
for(j:=0;j<ns;j++){
mm:=0;
while(evalf(simplify(subst(SS[j],n_1=mm)))<=evalf(maxi)){
S:=concat(S,simplify(subst(SS[j],n_1=mm)));mm:=mm+1;
};mm:=-1;
while(evalf(subst(SS[j],n_1=mm))>=evalf(mini)){
S:=concat(S,simplify(subst(SS[j],n_1=mm)));mm:=mm-1;
}
}

}else{
S:=concat(S,solve(L[k](x),x));
}





  si size(S)>0 alors   pour j de 0 jusque size(S)-1 faire
                          if(S[j]>mini and S[j]<maxi){Z:=Z,simplify(S[j]);}
                      fpour;
  fsi;
fpour;


pour k de 0 jusque m-1 faire



if(trigo==t){
all_trig_solutions:=1;
reset_solve_counter(-1,-1);
SSF:=solve(factor(simplify(Fo[k](x))),x);
nsf:=size(SSF);
for(j:=0;j<nsf;j++){
mm:=0;
while(evalf(simplify(subst(SSF[j],n_1=mm)))<=evalf(maxi)){
SF:=concat(SF,simplify(subst(SSF[j],n_1=mm)));mm:=mm+1;
};mm:=-1;
while(evalf(subst(SSF[j],n_1=mm))>=evalf(mini)){
SF:=concat(SF,simplify(subst(SSF[j],n_1=mm)));mm:=mm-1;
}
}

}else{
SF:=concat(SF,solve(Fo[k](x),x));
}

  si size(SF)>0 alors pour j de 0 jusque size(SF)-1 faire
                          FF:=FF,simplify(SF[j]);
                          if(SF[j]>mini and SF[j]<maxi){F:=F,simplify(SF[j]);}
                      fpour;
  fsi;
fpour;



Z:=[Z,F];


Z:=sort([op(set[op(Z)])]);

nz:=size(Z);

if(nz==0){li:="";l0:="val(btex $"+latex(D[0])+"$ etex);val(btex $"+latex(D[1])+"$ etex);";
          for(p:=0;p<=n-1;p++){li:=li+lsic+latex(L[p](x))+"}$ etex);"+
if(mini!=-infinity and L[p](mini)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+
if(L[p]((mini+maxi)*0.5>0)){"plus;"}else{"moins;"}+if(maxi!=+infinity and L[p](maxi)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}

}
           lf:=if(product(L[s]((mini+maxi)*.5),s,0,n-1)>0){"plus;"}else{"moins;"};




MetaLfc:="
beginTableau("+nmr+")
newLigneVariables(btex $ {x}$ etex);
   "+l0+li+
   lsic+nomf+"(x)}$ etex);"+
              if(member(mini,FF)==0){if((mini!=-infinity) and (product(L[s](mini),s,0,n-1)==0)){" valBarre(btex 0 etex);"}else{" "}}else{"nonDefBarre;"}+  lf+
              if(member(maxi,FF)==0){if((maxi!=+infinity) and (product(L[s](maxi),s,0,n-1)==0)){" valBarre(btex 0 etex);"}else{" "}}else{"nonDefBarre;"}+"
endTableau;

"
;




}else{


l0:="val(btex $"+latex(D[0])+"$ etex);";li:=" ";lr:=" ";
pour m de 0 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";fpour;
l0:=l0+"val(btex $"+latex(D[1])+"$ etex);";


for(p:=0;p<=n-1;p++){lp:="";
     li:=li+lsic+latex(L[p](x))+"}$ etex);"+
           if(mini!=-infinity and L[p](mini)==0){" valBarre(btex 0 etex);"}else{" "}+
           if(L[p](Z[0]-0.01)>0){"plus;"}else{"moins;"};

     for(r:=0; r<=nz-2;r++){lp:=lp+if(simplify(L[p](Z[r]))==0){" valBarre(btex 0 etex);"}else{"barre;"}+
                             if(L[p]((Z[r]+Z[r+1])*.5)>0){"plus;"}else{"moins;"}};

                li:=li+lp+ if(simplify(L[p](Z[nz-1]))==0){"valBarre(btex 0 etex);"}else{"barre;"}+
                          if(L[p](evalf(Z[nz-1])+1.0)>0){"plus;"}else{"moins;
    "}+if(maxi!=+infinity and L[p](maxi)==0){"valBarre(btex 0 etex);"}else{" "}

    };


pour t de 0 jusque nz-2 faire
                           lr:=lr+if(product(L[s]((Z[t]+Z[t+1])*.5),s,0,n-1)>0){"plus;"}else{"moins;"}+
                                      if(member(Z[t+1],FF)==0){"valBarre(btex 0 etex);"}else{ "nonDefBarre;"}
                         fpour




MetaLfc:="
beginTableau("+nmr+")
newLigneVariables(btex $ {x}$ etex);
   "+l0+
                     li
                     +
   lsic+nomf+"(x)}$ etex);"+
               if(member(mini,FF)==0){if((mini!=-infinity) and (product(L[s](mini),s,0,n-1)==0)){" valBarre(btex 0 etex);"}else{" "}}else{"nonDefBarre;"}+
                         if(product(L[s](evalf(Z[0])-0.01),s,0,n-1)>0){"plus;"}else{"moins;"}+
                         if(member(Z[0],FF)==0){"valBarre(btex 0 etex);"}else{ "nonDefBarre;"}+
                         lr+
                         if(product(L[s](evalf(Z[nz-1])+0.01),s,0,n-1)>0){"plus;"}else{"moins;"}+
                         if(member(maxi,FF)==0){if((maxi!=+infinity) and (product(L[s](maxi),s,0,n-1)==0)){"valBarre(btex 0 etex);"}else{" "}}else{"nonDefBarre;"}+"
endTableau;

"


}




sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);





 }:;

