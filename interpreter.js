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
	
	return {
		'getPointer': () => {
			return pointer;
		},
		'getSource': () => {
			let code = '';
		},
		'>': () => {
			if(pointer < memLength) { 
				pointer++; 
			}
			console.log('> => ', pointer, ': ', tape[pointer]);
		},
		'<': () => {
			if(pointer > 0) { 
				pointer--; 
			}
			console.log('< => ', pointer, ': ', tape[pointer]);
		},
		'+': () => {
			tape[pointer] = tape[pointer] + 1;
			console.log('+ => ', pointer, ": ", tape[pointer]);
		},
		'-': () => {
			tape[pointer] = tape[pointer] - 1;
			console.log('- => ', pointer, ': ', tape[pointer]);
		},
		'.': () => {
			console.log(tape[pointer]);
		},
		',': () => {
			//tape[pointer] = readInput(val);
		},
		'[': () => {
			console.log("WTF pointer is", pointer, "val is:", tape[pointer]);
			if(tape[pointer] === 0) {
				console.log("Reached [, finding matching ]...");
				while(source[index] !== ']') { 
					index++; 
				} 
				console.log("Matching ] found at index:", index, source[index]);
				index++;
			}
			else {
				console.log("Reached [", tape[pointer], index, source[index]);
			}
		},
		//when we reach ] and the loop has terminated, we advance to 1 after ]
		']': () => {
			//problem is we need to find the MATCHING '[' and not just the next one we find
			console.log("POINTER:", pointer, "VAL:", tape[pointer], source[index]);
			if(tape[pointer] !== 0) {
				console.log("Reached ], finding matching [...");
				while(source[index] !== '[') {
					index--;
				}
				console.log("Matching [ found at index:", index, source[index]);
			}
			else {
			}
		},
		readInput
	};
} (30000));

let term = 0;

let max = 0;
let button = document.getElementById("read");
button.addEventListener("click", function() {
	let c;
	while((c = b.readInput()) !== "#" && max < 200) {
		max++;
		b[c]();
	}
   	//let c = b.readInput();
   	//b[c]();
});
