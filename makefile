All: ffp kk


ffp: FFpr.o	
	g++ -o ffp FFpr.o

clean:
	rm -f ffp

kk: ffp 
	./ffp
