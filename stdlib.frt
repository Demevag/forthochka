: here forth-here @ ; 

: rot swap >r swap r> ;

: IMMEDIATE forth-last-word @ forth-cfa 1 - dup c@ 1 or swap c! ;

: if ' 0branch , here 0  , ; IMMEDIATE
: else ' branch , here 0 , swap here swap !  ; IMMEDIATE
: then here swap ! ; IMMEDIATE

: while here ' 0branch , here 0 , swap ; IMMEDIATE
: endile ' branch , here 0 , ! here swap ! ; IMMEDIATE

: forn ' >r ,
	   ' swap ,
	   ' r> ,
	   ' swap ,
       ' >r ,
       ' >r ,
       ' >r , 
  here ' r> , ' r@ , ' + , ' dup , ' r> , ' r@ , ' swap , ' >r , ' < , ' swap , ' >r ,
	   ' 0branch , here 0 , swap ; IMMEDIATE
: endforn 
		  ' branch , here 0 , ! here swap !
          ' r> ,
          ' r> ,
          ' r> ,
          ' drop ,
          ' drop ,
          ' drop , ; IMMEDIATE

: drop_n >r r@ while drop r> 1 - dup >r endile r> drop ;
