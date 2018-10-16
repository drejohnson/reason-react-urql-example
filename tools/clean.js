const path = require('path')
const fs = require('fs-extra')
const config = require('./config')

async function clean() {
  try {
    await fs.emptyDir(config.resolveApp('dist'))
    console.log('success!')
  } catch (err) {
    console.error(err)
  }
}

clean()
