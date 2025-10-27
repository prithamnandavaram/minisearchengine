# Railway/Render Build Script
echo "🔨 Building C++ Search Engine..."
g++ -o search_engine Mini_Search_Engine_CLI.cpp -std=c++11

echo "📦 Installing Node.js dependencies..."
cd web-interface && npm install

echo "✅ Build completed successfully!"