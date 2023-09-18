import process from 'process';
import glob from 'glob';
import CppjsCompiler from 'cpp.js';
import getDirName from 'cpp.js/src/utils/getDirName.js';

process.chdir('../');
const compiler = new CppjsCompiler();

const headers = [];
compiler.config.paths.header.forEach(header => {
    compiler.config.ext.header.forEach(ext => {
        headers.push(
            ...glob.sync(`${header}/*.${ext}`, { absolute: true, cwd: compiler.config.paths.project }),
            ...glob.sync(`${header}/**/*.${ext}`, { absolute: true, cwd: compiler.config.paths.project }),
        );
    });
});

headers.forEach(header => {
    compiler.findOrCreateInterfaceFile(header);
});

compiler.createBridge();
const params = compiler.getCmakeParams();

params.forEach((param, i) => {
    if (param.startsWith('-DHEADER_DIR=')) {
        params[i] += `;${compiler.config.paths.project}/node_modules/react-native-cppjs/cpp/src;${compiler.config.paths.project}/node_modules/react-native-embind/cpp/src;${compiler.config.paths.project}/node_modules/react-native/ReactCommon/jsi`
    } else if (param.startsWith('-DNATIVE_GLOB=')) {
        params[i] += `;${compiler.config.paths.project}/node_modules/react-native-cppjs/cpp/src/JSI_module.cpp;${compiler.config.paths.project}/node_modules/react-native-embind/cpp/src/emscripten/bind.cpp;${compiler.config.paths.project}/node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp`;
    }
});

params.push(...[
    '-DPROJECT_NAME=react-native-cppjs',
    '-DBUILD_TYPE=SHARED',
]);

console.log(params.join(';;;'));