const fs = require('fs')
const path = require('path')

const appDirectory = fs.realpathSync(process.cwd())

async function appDir() {
  try {
    await fs.realpath(process.cwd())
    console.log('success!')
  } catch (err) {
    console.error(err)
  }
}

module.exports = {
  resolveApp: relativePath => path.resolve(appDirectory, relativePath)
}
