<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Website Creator</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        textarea, input, select {
            width: 100%;
            margin: 10px 0;
            padding: 10px;
            font-size: 16px;
        }
        button {
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <h1>Create Your Website</h1>
    <label for="title">Website Title:</label>
    <input type="text" id="title" placeholder="Enter website title" />

    <label for="content">Website Content:</label>
    <textarea id="content" placeholder="Enter website content"></textarea>

    <label for="style">Custom CSS (Optional):</label>
    <textarea id="style" placeholder="Enter custom CSS"></textarea>

    <label for="detail">How detailed should the website be?</label>
    <select id="detail">
        <option value="simple">Simple</option>
        <option value="detailed">Detailed</option>
    </select>

    <button onclick="submitWebsite()">Create Website</button>

    <script>
        async function submitWebsite() {
            const title = document.getElementById('title').value;
            const content = document.getElementById('content').value;
            const style = document.getElementById('style').value;
            const detail = document.getElementById('detail').value;

            const response = await fetch('/create-website', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ title, content, style, detail })
            });

            const result = await response.json();
            if (result.success) {
                alert(`Website created! Access it here: ${result.url}`);
                window.open(result.url, '_blank');
            } else {
                alert('Failed to create website. Try again.');
            }
        }
    </script>
</body>
</html>
