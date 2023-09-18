All: ffp kk


ffp: FFpr.o	
	g++ -o ffp FFpr.o

clean:
	Rm -f ffp

kk: ffp 
	./ffp