// Registration Form Validation
document.getElementById('registerForm').addEventListener('submit', function(event) {
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('confirmPassword').value;
  
    if (!/^[^ ]+@[^ ]+\.[a-z]{2,3}$/.test(email)) {
      alert("Please enter a valid email.");
      event.preventDefault();
    }
  
    if (password !== confirmPassword) {
      alert("Passwords do not match.");
      event.preventDefault();
    }
  
    if (password.length < 8) {
      alert("Password must be at least 8 characters.");
      event.preventDefault();
    }
  });
  
  // Add to Cart Functionality
  let cart = [];
  
  function addToCart(productId) {
    cart.push(productId);
    alert("Product added to cart!");
    updateCartView();
    const button = document.querySelector(`button[onclick="addToCart(${productId})"]`);
    animateAddToCart(button);
  }
  
  function updateCartView() {
    const cartContents = document.getElementById('cartContents');
    cartContents.innerHTML = cart.length ? `Products in cart: ${cart.length}` : 'Your cart is empty.';
  }
  
  // Add to Cart Animation
  function animateAddToCart(button) {
    button.classList.add('pulse');
    setTimeout(() => button.classList.remove('pulse'), 500);
  }
  
  // Video Integration
  document.getElementById('playVideoBtn').addEventListener('click', function() {
    const videoContainer = document.getElementById('videoContainer');
    videoContainer.innerHTML = `<iframe width="560" height="315" src="https://www.youtube.com/embed/example-video" frameborder="0" allowfullscreen></iframe>`;
  });  