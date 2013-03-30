/^1\.[0-9]$/ {
	trgt = gensub (/^1\.([0-9])$/, "1.0\\1", 1);
	system ("git mv " $0 " " trgt);
}
