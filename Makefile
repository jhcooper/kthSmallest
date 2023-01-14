make: kthsmallest.cc
	g++ -o kth kthsmallest.cc
clean:
	rm -f kth
go:
	./kth
