/**
 * @param {number} init
 * @return { { increment: () => number, decrement: () => number, reset: () => number } }
 */
var createCounter = function(init) {
    let curr = init;

    return{
        increment: function(){
            curr += 1;
            return curr;
        },
        decrement: function() {
            curr -= 1;
            return curr;
        },
        reset: function() {
            curr = init;
            return curr;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */