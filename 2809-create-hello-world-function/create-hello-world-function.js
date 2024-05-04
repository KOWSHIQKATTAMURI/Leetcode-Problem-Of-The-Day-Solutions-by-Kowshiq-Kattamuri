/**
 * @return {Function}
 */
var createHelloWorld = function(){
    return function(...args){
        var out = "Hello World";
        return out;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */