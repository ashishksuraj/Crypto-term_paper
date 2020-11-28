TSa(a,b,c,d,nmr):={
zA:=solve(a*x+b=0,x)[0];
zB:=solve(c*x+d=0,x)[0];
zmin:=min(zA,zB);
zmax:=max(zA,zB);
  Meta:= "
          beginTableau("+nmr+")
   newLigneVariables(btex $ {x}$ etex);
   val(btex $-\\infty$ etex);val(btex $"+latex(zmin)+"$ etex);
val(btex $"+latex(zmax)+"$etex);
val(btex $+\\infty$ etex);
  "+lsic+if(a==1){"x+"}else{if(a==-1){"-x+"}else{a+"x+"}}+b+"}$ etex);"
        +   if(a>0){"moins;"}else{"plus;"}+
                                 if(zmin==zA){"valBarre(btex 0 etex);"}else{"barre;"}+
                                 if(zmin==zA){si a>0 alors "plus;"; sinon "moins;";fsi}
                                             else{si a>0 alors "moins;"; sinon "plus;"; fsi}+
                                 if(zmin==zA){"barre;"}else{"valBarre(btex 0 etex);"}+
                                 if(a>0){"plus;"}else{"moins;"}
     +lsic+if(c==1){"x+"}else{if(c==-1){"-x+"}else{c+"x+"}}+d+"}$ etex);"
        +     if(c>0){"moins"}else{"plus"}+";"+
                                 if(zmin==zB){"valBarre(btex 0 etex);"}else{"barre;"}+
                                 if(zmin==zB){si c>0 alors "plus;"; sinon "moins;";fsi}
                                             else{si c>0 alors "moins;"; sinon "plus;"; fsi}+
                                 if(zmin==zB){"barre;"}else{"valBarre(btex 0 etex);"}+
                                 if(c>0){"plus;"}else{"moins;"}

   +lsic+"{("+if(a==1){"x+"}else{if(a==-1){"-x+"}else{a+"x+"}}+b+")("+if(c==1){"x+"}else{if(c==-1){"-x+"}else{c+"x+"}}+d+")}}$ etex);"
        +   si a*c>0 alors plus; sinon moins;fsi+";"+
                                 "valBarre(btex 0 etex);"+
                                 si a*c>0 alors moins; sinon plus;fsi+";"+
                                 "valBarre(btex 0 etex);"+
                                 si a*c>0 alors plus; sinon moins;fsi+";"+"
endTableau;
"
;



sortie:=fopen("XCasmpfc.mp");
fprint(sortie,Unquoted,Meta);
fclose(sortie);


 }:;
