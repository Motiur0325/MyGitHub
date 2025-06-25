document.getElementsByClassName('btn-input')[0].addEventListener('click',updateArray)
var arr=new Array()
function updateArray(event){

    var button=event.target
    var number=button.parentElement.getElementsByClassName('number-input')[0].value
    arr.push(parseInt(number))
    // console.log(button,number)
    document.getElementsByClassName('array-input-list')[0].innerHTML+=`<span>${number} </span>`
}
document.getElementsByClassName('btn-output')[0].addEventListener('click',bubbleSort)
function bubbleSort(){
    for(var i=0;i<arr.length-1;i++){
        for(var j=0;j<arr.length-i-1;j++){
            if(arr[j]>arr[j+1]){
                var temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp
            }
        }
    }
    sortedArray(arr)
}
function sortedArray(arr){
    document.getElementsByClassName('array-output-list')[0].innerHTML=`<span></span>`
    for(var i=0;i<arr.length;i++){
        var number=arr[i]
        document.getElementsByClassName('array-output-list')[0].innerHTML+=`<span>${number} </span>`
    }
}