#!/usr/bin/perl
#!/usr/bin/env perl

# Author: Alejandro Parana
# Date: 3/20/2016
# WordCount Perl

open (IN, "<", "words.txt") or die "Error opening INPUT file!";

%hash = ();
while ($line = <IN>)  {
	$_ = $line;
	$result = s/\.//g;
	@words = split /\s/, $_; 

	foreach $w(@words) {
	   $k = uc $w;
	   if (exists $hash{$k}) {
	       $hash{$k}++;  	
	   }
	   else {
	   	$hash{$k} = 1;
	   }
	}
}
print("========RESULTS===========\n");
while(my($key, $value) = each %hash ) {
  if ($value == 1) {
  	 print "$key was used $value time.\n";
  }
  else {
  	 print "$key was used $value times.\n";
  }
}
print("==========================\n");
