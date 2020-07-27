#/bin/sh

BASHRC="(HOME)/.bashrc"
ZSHRC="$HOME/.zshrc"
ALIPATH="$(pwd)/aliases.txt"

trap 'echo "Не убивай меня"' SIGINT SIGTERM SIGQUIT SIGTSTP SIGCONT

function WriteAliases
{
	while IFS= read -r line
	do
		printf "$line\n" >> $BASHRC
		#printf "$line\n" >> $ZSHRC
	done < $1
}

function WriteAllStuff {
	WriteAliases $ALIPATH
	printf "PATH=\$PATH:\$HOME/bin\ncat\n" >> $BASHRC
	printf "PATH=\$PATH:\$HOME/bin\ncat\n" >> $ZSHRC
	mkdir -p $HOME/bin
	cp AmazingShellCommand.sh $HOME/bin/AmazingShellCommand
	cp WhereIsNasvai.sh $HOME/bin/WhereIsNasvai
	cp NasvaiSpeech.txt $HOME/bin
	cp Perdezh.sh $HOME/bin/Perdezh
	cp P $HOME/bin
}

WriteAllStuff
