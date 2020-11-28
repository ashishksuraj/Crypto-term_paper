

TS(nomf,L,D,trigo,nmr):={
L:=apply(f->unapply(f,x),L)
n:=size(L);
Z:=NULL;
nl:=size(L);
S:=[];
mini:=D[0]; maxi:=D[1];

pour k de 0 jusque n-1 faire




if(trigo==t){
all_trig_solutions:=1;
reset_solve_counter(-1,-1);
SS:=solve(factor(simplify(L[k](x))),x);
ns:=size(SS);
for(j:=0;j<ns;j++){
m:=0;
while(evalf(simplify(subst(SS[j],n_1=m)))<=evalf(maxi)){
S:=concat(S,simplify(subst(SS[j],n_1=m)));m:=m+1;
};m:=-1;
while(evalf(subst(SS[j],n_1=m))>=evalf(mini)){
S:=concat(S,simplify(subst(SS[j],n_1=m)));m:=m-1;
}
}

}else{
S:=solve(L[k](x),x);
}




  si size(S)>0 alors  pour j de 0 jusque size(S)-1 faire
                          if(S[j]>mini and S[j]<maxi){Z:=Z,simplify(S[j]);}
                      fpour;
  fsi;
fpour;





Z:=sort(Z);
nz:=size(Z);


 Z:=sort([op(set[(Z)])]);


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


MetaLfc:="    beginTableau("+nmr+")
newLigneVariables(btex $ {x}$ etex);
   "+l0+li+ lsic+nomf+"(x)}$ etex);"+
               if(mini!=-infinity and product(L[s](mini),s,0,n-1)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+  lf+
                               if(maxi!=+infinity and product(L[s](maxi),s,0,n-1)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+"
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
           if(mini!=-infinity and L[p](mini)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+
           if(L[p](Z[0]-0.01)>0){"plus;"}else{"moins;"};

                           for(r:=0; r<=nz-2;r++){
                             lp:=lp+if(simplify(L[p](Z[r]))==0){"
                                valBarre(btex 0 etex);"}else{"barre;
                              "}+
                             if(L[p]((Z[r]+Z[r+1])*.5)>0){"plus;"}else{"moins;"}};

                li:=li+lp+ if(simplify(L[p](Z[nz-1]))==0){"valBarre(btex 0 etex);"}else{"barre;"}+
                          if(L[p](Z[nz-1]+1.0)>0){"plus;"}else{"moins;
    "}+if(maxi!=+infinity and L[p](maxi)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}
    };


pour t de 0 jusque nz-2 faire
                           lr:=lr+if(product(L[s]((Z[t]+Z[t+1])*.5),s,0,n-1)>0){"plus;"}else{"moins;"}+"valBarre(btex 0 etex);"
                         fpour

MetaLfc:="  beginTableau("+nmr+")
newLigneVariables(btex $ {x}$ etex);
   "+l0+
                     li
                     + lsic+nomf+"(x)}$ etex);"+
               if(mini!=-infinity and product(L[s](mini),s,0,n-1)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+
                         if(product(L[s](evalf(Z[0])-0.01),s,0,n-1)>0){"plus;"}else{"moins;"}+"valBarre(btex 0 etex);"+
                         lr+
                         if(product(L[s](evalf(Z[nz-1])+0.01),s,0,n-1)>0){"plus;"}else{"moins;"}+
                               if(maxi!=+infinity and product(L[s](maxi),s,0,n-1)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}+"
endTableau;

 ";
}
sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);

 }:;

