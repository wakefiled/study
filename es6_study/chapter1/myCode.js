
one = 100;
function get(){
	one = 300;
	console.log("Func:",one);
}
get();
console.log("Global:",one);