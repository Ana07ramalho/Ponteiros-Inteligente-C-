# Nome do arquivo de saída
TARGET = programa

# Compilador C++
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte
SRCS = main.cpp Time.cpp Clube.cpp  Selecao.cpp Competicao.cpp Eliminatoria.cpp Brasileirao.cpp

# Arquivos objeto gerados a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Regra padrão para criar o programa
all: $(TARGET)

# Regra para criar o programa a partir dos arquivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para gerar os arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos intermediários e do programa
clean:
	rm -f $(OBJS) $(TARGET)
