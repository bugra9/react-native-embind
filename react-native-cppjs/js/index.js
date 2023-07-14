import { NativeModules } from 'react-native';
import z from 'react-native-embind';

const { RNJsiLib } = NativeModules;
RNJsiLib.start();


export default z;
