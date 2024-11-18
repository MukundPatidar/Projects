// script.js

// Initialize cart count
// let cartCount = 0;

// // Function to update cart count in the DOM
// function updateCartCount() {
//     document.getElementById('cart-count').textContent = cartCount;
// }

// // Function to handle "Add to Cart" button clicks
// function addToCart(event) {
//     if (event.target.classList.contains('add-to-cart')) {
//         cartCount++;
//         updateCartCount();
//         // Optionally, you can add more functionality like storing cart items
//         alert('Item added to cart!');
//     }
// }

// // Add event listener to the product list for event delegation
// document.querySelector('.product-list').addEventListener('click', addToCart);



// Example product data
const products = [
    {
        id: 1,
        title: "Product Title 1",
        price: 19.99,
        image: "https://via.placeholder.com/200"
    },
    {
        id: 2,
        title: "Product Title 2",
        price: 29.99,
        image: "https://via.placeholder.com/200"
    },
    // Add more products as needed
];

// Function to display products
function displayProducts() {
    const productList = document.querySelector('.product-list');
    products.forEach(product => {
        const productCard = document.createElement('div');
        productCard.className = 'product-card';
        
        productCard.innerHTML = `
            <img src="${product.image}" alt="${product.title}">
            <h3>${product.title}</h3>
            <p>$${product.price.toFixed(2)}</p>
            <button class="add-to-cart" data-id="${product.id}">Add to Cart</button>
        `;
        
        productList.appendChild(productCard);
    });
}

// Call the function on page load
window.onload = displayProducts;



// Initialize cart count from localStorage
let cartCount = parseInt(localStorage.getItem('cartCount')) || 0;

// Function to update cart count in the DOM and localStorage
function updateCartCount() {
    document.getElementById('cart-count').textContent = cartCount;
    localStorage.setItem('cartCount', cartCount);
}

// Function to handle "Add to Cart" button clicks
function addToCart(event) {
    if (event.target.classList.contains('add-to-cart')) {
        const productId = event.target.getAttribute('data-id');
        cartCount++;
        updateCartCount();
        alert('Item added to cart!');
    }
}

// Add event listener to the product list for event delegation
document.querySelector('.product-list').addEventListener('click', addToCart);

// Display products on page load
window.onload = displayProducts;
