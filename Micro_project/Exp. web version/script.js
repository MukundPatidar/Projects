// Function to generate a 4-digit unique ID
function generateUniqueId() {
    return Math.floor(1000 + Math.random() * 9000);
}

// Function to save record to localStorage
function saveRecord(record) {
    let records = JSON.parse(localStorage.getItem('records')) || [];
    records.push(record);
    localStorage.setItem('records', JSON.stringify(records));
}

// Function to get all records from localStorage
function getRecords() {
    return JSON.parse(localStorage.getItem('records')) || [];
}

// Function to update record in localStorage
function updateRecord(updatedRecord) {
    let records = getRecords();
    records = records.map(record => record.id === updatedRecord.id ? updatedRecord : record);
    localStorage.setItem('records', JSON.stringify(records));
}

// Function to delete record from localStorage
function deleteRecord(id) {
    let records = getRecords();
    records = records.filter(record => record.id !== id);
    localStorage.setItem('records', JSON.stringify(records));
}

// Function to calculate total income, expense, and balance
function calculateBalance() {
    const records = getRecords();
    let income = 0, expense = 0;
    records.forEach(record => {
        if (record.type === 'income') {
            income += parseFloat(record.amount);
        } else {
            expense += parseFloat(record.amount);
        }
    });
    return { income, expense, balance: income - expense };
}

// Function to download records as CSV
function downloadRecords() {
    const records = getRecords();
    let csvContent = "data:text/csv;charset=utf-8,";
    csvContent += "ID,Date,Type,Category,Amount,Remark\n";
    records.forEach(record => {
        csvContent += `${record.id},${record.date},${record.type},${record.category},${record.amount},${record.remark}\n`;
    });
    const encodedUri = encodeURI(csvContent);
    const link = document.createElement("a");
    link.setAttribute("href", encodedUri);
    link.setAttribute("download", "records.csv");
    document.body.appendChild(link);
    link.click();
}