MAIN = pext-prog2-benante-03

all:
	pdflatex $(MAIN)
	bibtex $(MAIN)
	pdflatex $(MAIN)
	pdflatex $(MAIN)

clean:
	rm -f *.aux *.log *.bbl *.blg *.toc *.out

distclean: clean
	rm -f $(MAIN).pdf