default: build

build:
	@clear
	@g++ *.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system || (echo "\n==> $(tput setaf 1)Failed chỗ nào đó rồi cưng\n$(tput sgr0)"; exit 1)
	@echo "\n==> $(tput setaf 2)Thành cmn công :)  Đề mô bằng lệnh $(tput sgr0)make run$(tput setaf 2) hoặc lệnh $(tput sgr0)./a.out$(tput sgr0)\n"

run:
	./a.out || true

clean:
	rm a.out
