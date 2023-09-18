import process from 'process';
import CppjsCompiler from 'cpp.js';

process.chdir('../');
const compiler = new CppjsCompiler();

console.log(compiler.config.paths.cli);
