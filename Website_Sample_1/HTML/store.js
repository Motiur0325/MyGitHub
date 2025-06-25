if(document.readyState == 'loading'){
    document.addEventListener('DOMContentLoaded',ready)
}
else{
    ready()
}
function ready(){
    var removeCartItems=document.getElementsByClassName('btn-danger')
    for(var i=0;i<removeCartItems.length;i++){
        var button=removeCartItems[i];
        button.addEventListener('click',removeCartItem)
    }
    var itemQuantity=document.getElementsByClassName('cart-item-quantity')
    for(var i=0;i<itemQuantity.length;i++){
        var input=itemQuantity[i]
        input.addEventListener('change',quantityChanged)
    }
    var addToCartButton=document.getElementsByClassName('shop-item-btn')
    for(var i=0;i<addToCartButton.length;i++){
        var button=addToCartButton[i]
        button.addEventListener('click',addToCartClicked)
    }
    document.getElementsByClassName('btn-purchase')[0].addEventListener('click',itemPurchased)
}
function itemPurchased(event){
    alert("Thank You for the Purchase!!")
    var cartItems=document.getElementsByClassName('cart-items')[0]
    while(cartItems.hasChildNodes()){
        cartItems.removeChild(cartItems.firstChild)
    }
    updateCartTotal()
}
function addToCartClicked(event){
    var button=event.target
    var shopItem=button.parentElement.parentElement
    var title=shopItem.getElementsByClassName('shop-item-title')[0].innerText
    var img=shopItem.getElementsByClassName('shop-item-img')[0].src
    var price=shopItem.getElementsByClassName('shop-item-price')[0].innerText
    addItemToCart(title,price,img)
    updateCartTotal()
}
function addItemToCart(title,price,img){
    var cartRow=document.createElement('div')
    var cartItems=document.getElementsByClassName('cart-items')[0]
    var cartItemNames=cartItems.getElementsByClassName('cart-item-title')
    for(var i=0;i<cartItemNames.length;i++){
        if(cartItemNames[i].innerText==title){
            alert("This item is already added to cart!!")
            return
        }
    }
    var cartRowContents=`
        <div class="cart-row">
            <div class="cart-item cart-column">
                <img class="cart-item-img" src="${img}" width="100">
                <span class="cart-item-title">${title}</span>
            </div>
            <span class="cart-item-price cart-column">${price}</span>
            <div class="cart-quantity cart-column">
                <input class="cart-item-quantity" type="number" value="1">
                <button class="btn btn-danger" type="button">REMOVE</button>
                <span class="invalid"></span>
            </div>
        </div>`
    cartRow.innerHTML=cartRowContents
    cartItems.append(cartRow)
    cartRow.getElementsByClassName('btn-danger')[0].addEventListener('click',removeCartItem)
    cartRow.getElementsByClassName('cart-item-quantity')[0].addEventListener('change',quantityChanged)
}
function quantityChanged(event){
    var input=event.target
    if(isNaN(input.value)||input.value<=0){
        input.value=1
        alert('Please Enter a valid quantity!!')
    }
    updateCartTotal()
}
function removeCartItem(event){
    var buttonClicked=event.target
    buttonClicked.parentElement.parentElement.remove()
    updateCartTotal()
}
function updateCartTotal(){
    var cartItems=document.getElementsByClassName('cart-items')[0]
    var cartRows=cartItems.getElementsByClassName('cart-row')
    var total=0
    for(var i=0;i<cartRows.length;i++){
        var cartRow=cartRows[i]
        var priceElement=cartRow.getElementsByClassName('cart-item-price')[0]
        var quantityElement=cartRow.getElementsByClassName('cart-item-quantity')[0]
        var price=parseFloat(priceElement.innerText.replace('$',''))
        var quantity = quantityElement.value
        total=total+(price*quantity)
    }
    total=Math.round(total*100)/100
    document.getElementsByClassName('cart-total-price')[0].innerText='$'+total
}