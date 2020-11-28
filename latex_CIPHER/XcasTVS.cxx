TVS(La,Lo,F,nomf,nomv,nmr):={

na:=size(La);
f:=F;
if(member(La[0],F)){f:=f[1..size(f)-1]};
if(member(La[na-1],F)){f:=f[0..size(f)-2]};
Z:=sort(concat(La,f));
Zo:=sort([op(set[op(Z)])]);
nz:=size(Z);
nzo:=size(Zo);


k0:= evalf(Lo[0])> evalf(Lo[1]);
kz:=evalf(Lo[nz-1])> evalf(Lo[nz-2]);


l0:=" newLigneVariables(btex $"+nomv+"$ etex);";lp:=" "; lf:=" ";
  for(m:=0;m<=nzo-1;m++){l0:=l0+"val(btex $"+latex(Zo[m])+"$ etex);"}

li:=lvic+nomf+"}$ etex);"+
    if(member(Z[0],F)==0){"valPos(btex $"+latex(Lo[0])+"$ etex,"}
    else{"nonDefBarre;limDroite(btex $"+latex(Lo[0])+"$ etex,"}+
           if(k0==1){"1"}else{"0"}+
                         ");";

    if(nz>2){ for(r:=1; r<=nz-2;r++){
         krm:=evalf(Lo[r-1])< evalf(Lo[r]);
         krp:=evalf(Lo[r])> evalf(Lo[r+1]) ;

      lp:=lp+if(Z[r]==Z[r+1]){
         "limGauche(btex$"+latex(Lo[r])+"$etex,"+
              if(krm==1){"1);"}
              else{"0);"}
             }// fin if zr=zr+1
             else{
              if(Z[r]==Z[r-1]){
         "nonDefBarre;limDroite(btex$"+latex(Lo[r])+"$etex,"+
              if(krp==1){"1);"}
              else{"0);"}
             }//fin if zr=zr-1
              else{
              "valPos(btex $"+latex(Lo[r])+"$etex,"+
              if(krp==1){"1);"}else{"0);"}
}//fin else zr=zr-1
}//fin else zr=zr+1
}//fin for
}//fin de if nz>2



lf:=if(member(Z[nz-1],F)==0){"valPos(btex $"+latex(Lo[nz-1])+"$ etex,"+
             if(kz==1){"1);"}else{"0);"}}
    else{"limGauche(btex $"+latex(Lo[nz-1])+"$ etex,"+
             if(kz==1){"1);nonDefBarre;"}else{"0);nonDefBarre;"}};


MetaLfc:=

 if(nz>2){"beginTableau("+nmr+")"+
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

";}

//return(MetaLfc);

sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,MetaLfc);
fclose(sortie);


}:;

