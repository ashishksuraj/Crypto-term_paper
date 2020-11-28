
TSc(g,D,F,trigo,nmr):={
f:=unapply(g,x);
mini:=D[0]; maxi:=D[1];lm:=" ";
Z:=mini,maxi;
S:=[];



if(trigo==t){
all_trig_solutions:=1;
reset_solve_counter(-1,-1);
SS:=solve(factor(simplify(f(x))),x);
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
S:=solve(f(x),x);
}





if(size(S)==0 and size(F)==0){
l0:="val(btex $"+latex(D[0])+"$ etex);val(btex $"+latex(D[1])+"$ etex);";
li:=if(member(mini,F)!=0){"nonDefBarre;"}else{if(mini!=-infinity and f(mini)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}}+
if(mini!=-infinity or maxi!=+infinity){if(f((mini+maxi)*0.5>0)){"plus;"}else{"moins;"}}else{if(f(0.3145274774464545777744)>0){"plus;"}else{"moins;"}};
lf:=if(member(maxi,F)!=0){"nonDefBarre;"}else{if(maxi!=+infinity and f(maxi)==0){"
                                valBarre(btex 0 etex);"}else{"
                              "}};
}else{
if(size(S!=0)){pour j de 0 jusque size(S)-1 faire
                           if(S[j]>mini and S[j]<maxi){Z:=Z,simplify(S[j])};
                      fpour}

Z:=concat([Z],F);

 Z:=sort([op(set[op(Z)])]);


nz:=size(Z);
l0:=" ";li:=" ";lr:=" ";
if(nz==2){l0:="val(btex $"+latex(D[0])+"$ etex);val(btex $"+latex(D[1])+"$ etex);";
li:=if(mini!=-infinity and f(mini)==0){"
                                valBarre(btex 0 etex);"}else{if(member(mini,F)==0){"
                              "}else{"nonDefBarre;"}}+
if(f((mini+maxi)*0.5)>0){"plus;"}else{"moins;"};
lf:=if(maxi!=+infinity and f(maxi)==0){"
                                valBarre(btex 0 etex);"}else{if(member(maxi,F)==0){"
                              "}else{"nonDefBarre;"}
                              };

}else{
l0:="val(btex $"+latex(Z[0])+"$ etex);";li:=" ";
pour m de 1 jusque nz-1 faire l0:=l0+"val(btex $"+latex(Z[m])+"$ etex);
";
fpour;


li:= if(mini!=-infinity and f(mini)==0){"
                                valBarre(btex 0 etex);"}else{if(member(mini,F)==0){"
                              "}else{"nonDefBarre;"}
                              }

lm:=if(nz>2){for(r:=0; r<nz-2;r++){lm:=lm+if(Z[r]==-infinity){
if(f((Z[r+1]-1))>0){"plus;"}else{"moins;"}
}else{if(f((Z[r]+Z[r+1])*.5)>0){"plus;"}else{"moins;"}}
+
            if(member(Z[r+1],F)==0){"valBarre(btex 0 etex);"}else{"nonDefBarre;"}
                           }}else{" "};

lf:=if(f(Z[nz-2]+0.1)>0){"plus;"}else{"moins;"}+if(maxi!=+infinity and f(maxi)==0){"valBarre(btex 0 etex);"}else{if(member(maxi,F)==0){"
                              "}else{"nonDefBarre;"}
                              };
}
};




MetaLfc:="

beginTableau("+nmr+")
newLigneVariables(btex $\\displaystyle  {x}$ etex);
   "+l0+lsic+latex(f(x))+"}$ etex);"+
                     li+lm+lf
                     +"
endTableau;

"
;




sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);
 }:;

