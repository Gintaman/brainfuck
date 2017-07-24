"use strict";
let source = '++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.';

let b = (function Brainfuck(memLength) {
	let tape = new Uint8Array(memLength);

	let pointer = 0; //pointer initialized to point to beginning of tape

	let index = -1;
	let readInput = function(val) {
		index++;
		return source[index];
	};

    let result = '';
	
	return {
		'>': () => {
			if(pointer < memLength) { 
				pointer++; 
			}
		},
		'<': () => {
			if(pointer > 0) { 
				pointer--; 
			}
		},
		'+': () => {
			tape[pointer] = tape[pointer] + 1;
		},
		'-': () => {
			tape[pointer] = tape[pointer] - 1;
		},
		'.': () => {
            result += (String.fromCharCode(tape[pointer]));
		},
		',': () => {
			//tape[pointer] = readInput(val);
		},
		'[': () => {
			if(tape[pointer] === 0) {
                let bal = 1;
                while(bal > 0) {
                    index++;
                    if(source[index] === '[') {
                        bal++;
                    }
                    else if(source[index] === ']') {
                        bal--;
                    }
                }
                index++;
			}
		},
		']': () => {
			if(tape[pointer] !== 0) {
                let bal = 1;
                while(bal > 0) {
                    index--;
                    if(source[index] === '[') {
                        bal--;
                    }
                    else if(source[index] === ']') {
                        bal++;
                    }
                }
			}
		},
        '#': () => {
            console.log(result);
        },
		readInput
	};
} (30000));

let term = 0;

let max = 0;
let button = document.getElementById("read");
button.addEventListener("click", function() {
	let c;
	while((c = b.readInput())) {
		max++;
		b[c]();
	}
    b['#']();
});
