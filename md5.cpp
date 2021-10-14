#include "md5.h"

int main()
{
  MD5 md5 ;
  puts( md5.digestString( "323" ) ) ;
  puts( md5.digestString( "323" ) ) ;
  puts ( md5.digestString ("fdfd"));
  

  // print the digest for a binary file on disk.
 // puts( md5.digestFile( "C:\\WINDOWS\\notepad.exe" ) ) ;

  return 0;
}
