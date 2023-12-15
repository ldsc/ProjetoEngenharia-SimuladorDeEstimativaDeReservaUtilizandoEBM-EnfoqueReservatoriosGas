#========================================================#
# Makefile para gerar versões da tese                    #
#========================================================#
# Comando               Gera o arquivo
# make dvi: 		ProjetoEngenharia-ManualDoDesenvolvedor.dvi
# make ps: 		ProjetoEngenharia-ManualDoDesenvolvedor.ps
# make pdf: 		ProjetoEngenharia-ManualDoDesenvolvedor.pdf
# make ps-2on1: 	ProjetoEngenharia-ManualDoDesenvolvedor-2on1.ps
# make pdf-2on1: 	ProjetoEngenharia-ManualDoDesenvolvedor-2on1.pdf

# Diretorio onde os arquivos temporarios serão armazenados
OUTPUT=/tmp/

all: dvi pdflatex
x2:  dvi ps 2on1.ps 
x:   dvi ps tex2pdf 
lyx: pdf 2on1.ps
pdflatex: pdflatex

#========================================================Gera o dvi a partir do latex
latex: dvi
dvi:  ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "No LyX você deve exportar o arquivo com a opção: file->export->Latex(simples)."
	echo "make dvi: gera arquivo da tese no formato dvi."
	echo "Running latex......(1)\a"
	latex ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Running BIBTEX.....(1b)\a"
	bibtex ProjetoEngenharia-ManualDoDesenvolvedor
	echo "ReRunning latex....(2)\a"
	latex ProjetoEngenharia-ManualDoDesenvolvedor.tex
# Retire o comentário das duas linhas abaixo se usar indice remissivo no final da tese
# echo "Running makeindex....(2b)\a"
# makeindex ProjetoEngenharia-ManualDoDesenvolvedor.idx
	echo "ReRunning latex....(3)\a"
	latex ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Rerunning latex....(4)\a"
	latex ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Rerunning latex....(5)\a"
	latex ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Versão da tese no formato dvi pronta."
	ls -lah ProjetoEngenharia-ManualDoDesenvolvedor.dvi

#========================================================Visualização do dvi
xdvi: ProjetoEngenharia-ManualDoDesenvolvedor.dvi
	echo "make xdvi: executa o visualizador do arquivo da tese no formato dvi."
	xdvi ProjetoEngenharia-ManualDoDesenvolvedor.dvi

#========================================================Gera ps a partir de dvi
dvips: ProjetoEngenharia-ManualDoDesenvolvedor.dvi
	echo "make ps: gera arquivo da tese no formato ps (Dimensoes A4)."
	dvips -D 600 -t portrait -T 21.0cm,29.7cm -o "ProjetoEngenharia-ManualDoDesenvolvedor.ps" ProjetoEngenharia-ManualDoDesenvolvedor.dvi
## dvips -o ProjetoEngenharia-ManualDoDesenvolvedor.ps ProjetoEngenharia-ManualDoDesenvolvedor.dvi

#========================================================Gera pdf a partir de ps
ps2pdf: ProjetoEngenharia-ManualDoDesenvolvedor.ps
	echo "make ps2pdf: converte arquivo ps para pdf (gera arquivo da tese no formato pdf)."
	echo "ps2pdf -sPAPERSIZE=a4 ..."
	ps2pdf -sPAPERSIZE=a4 ProjetoEngenharia-ManualDoDesenvolvedor.ps
#========================================================Gera 2on1.ps (formato brochura para costura)
2on1.ps: ProjetoEngenharia-ManualDoDesenvolvedor.ps
	echo "make 2on1.ps:  gera arquivo da tese no formato ps com 2 páginas em uma."
	echo "Executando psbook e pstops..."
	psbook -s20 ProjetoEngenharia-ManualDoDesenvolvedor.ps | pstops -pa4 "4:0@.7L(21cm,00)+1L@.7(21cm,14.8cm),2L@.7(21cm,00)+3L@.7(21cm,14.8cm)" > ProjetoEngenharia-ManualDoDesenvolvedor-2on1.ps

#========================================================Gera 2on1.pdf (duas páginas em uma)
2p: 	ProjetoEngenharia-ManualDoDesenvolvedor.ps
	echo "make 2p: Converte arquivo A4.ps em arquivo com 2 páginas em cada folha A4"
	cat ProjetoEngenharia-ManualDoDesenvolvedor.ps | pstops -pa4 "4:0@.7L(21cm,00)+1L@.7(21cm,14.8cm),2L@.7(21cm,00)+3L@.7(21cm,14.8cm)" > ProjetoEngenharia-ManualDoDesenvolvedor-2p.ps

#========================================================Gera 2on1.pdf
2on1.pdf: ProjetoEngenharia-ManualDoDesenvolvedor-2p.ps
	echo "make 2on1.pdf: gera arquivo da tese no formato pdf com 2 páginas em uma."
	ps2pdf ProjetoEngenharia-ManualDoDesenvolvedor-2p.ps

#========================================================Gera ps a partir de pdf
pdf2ps: ProjetoEngenharia-ManualDoDesenvolvedor.pdf
	echo "make pdf2ps: gera arquivo da tese no formato ps a partir da versão pdf."
	echo "pdf2ps..."
	pdf2ps -dLanguageLevel=1 ProjetoEngenharia-ManualDoDesenvolvedor.pdf ProjetoEngenharia-ManualDoDesenvolvedor.ps
#	echo "mpage..."

#========================================================Gera pdf usando pdflatex
pdflatex: ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "make pdflatex: gera arquivo da tese no formato pdf partindo diretamente do arquivo tex."
	echo "No LyX você deve exportar o arquivo com a opção: file->export->Latex(pdflatex)."
	echo "Running pdflatex...(1)\a"
	pdflatex ProjetoEngenharia-ManualDoDesenvolvedor.tex
#thumbpdf ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Running BIBTEX.....(1b)\a"
	bibtex ProjetoEngenharia-ManualDoDesenvolvedor
	echo "ReRunning pdflatex...(2)\a"
	pdflatex ProjetoEngenharia-ManualDoDesenvolvedor.tex
#thumbpdf ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Rerunning pdflatex....(3)\a"
	pdflatex ProjetoEngenharia-ManualDoDesenvolvedor.tex
#thumbpdf ProjetoEngenharia-ManualDoDesenvolvedor.tex
	echo "Rerunning pdflatex....(4)\a"
	pdflatex ProjetoEngenharia-ManualDoDesenvolvedor.tex
	acroread ProjetoEngenharia-ManualDoDesenvolvedor.pdf &

#========================================================Gera pdf usando tex2pdf direto
tex2pdf :
	echo "make tex2pdf: gera arquivo da tese no formato pdf partindo diretamente do arquivo tex."
	tex2pdf ProjetoEngenharia-ManualDoDesenvolvedor.tex

#========================================================Eliminando arquivos temporários
clean:
	echo "make clean: Eliminar os arquivos temporários."
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.lyx~ *.blg *.lof *.lot *.bbl *.brf *.nlo *~


#========================================================PROGRAMAS UTILIZADOS

# mpage: gera duas páginas em uma com borda (as vezes não funciona)
# psbook -s4 (cria livro rearranjando cada 4 páginas em 1)
# psbook -s40 (cria livro rearranjando cada 40 páginas em 10)
# pstops ?
# psnup coloca em  1 página A4 duas páginas

